#include <bits/stdc++.h>

using namespace std;

const int MAX_STAR = 1000;
const int MAX_STAR_PER_CONSTEL = 500;
const int NAME_LEN = 50;
const int COOR_BOUND = 100;
const int MAX_OCCUR = 500000;

struct Star
{
	int x, y, bright;
};

int starCmp(const void *star1, const void *star2)
{
	int res = ((Star *)star1)->x - ((Star *)star2)->x;
	if (res == 0)
	{
		res = ((Star *)star1)->y - ((Star *)star2)->y;
	}
	return res;
}

struct Constel
{
	char m_name[NAME_LEN];
	Star m_star[MAX_STAR_PER_CONSTEL];
	int m_cnt_star;

	void init()
	{
		m_cnt_star = 0;
	}
	void addStar(Star star)
	{
		m_star[m_cnt_star] = star;
		m_cnt_star++;
	}
	int bright()
	{
		int res = 0;
		for (int i = 0; i < m_cnt_star; i++)
		{
			res += m_star[i].bright;
		}
		return res;
	}
	void input()
	{
		scanf("%d%s", &m_cnt_star, m_name);
		for (int i = 0; i < m_cnt_star; i++)
		{
			scanf("%d%d", &m_star[i].x, &m_star[i].y);
		}
	}
	char *name()
	{
		return m_name;
	}
	void print_constel()
	{
		for (int i = 0; i < m_cnt_star; i++)
		{
			printf("(%d,%d)", m_star[i].x, m_star[i].y);
			if (i < m_cnt_star - 1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}
	Star star(int i)
	{
		return m_star[i];
	}
	int cnt_star()
	{
		return m_cnt_star;
	}
	void sort_star()
	{
		qsort(m_star, m_cnt_star, sizeof(Star), starCmp);
	}
};

bool m_have_star[COOR_BOUND * 2 + 1][COOR_BOUND * 2 + 1];
int m_star_no[COOR_BOUND * 2 + 1][COOR_BOUND * 2 + 1];

struct Map
{
	Star m_star[MAX_STAR];
	int m_cnt_star;
	inline int coorMap(int coor)
	{
		return coor + COOR_BOUND;
	}

	bool input()
	{
		bool have_nxt = false;
		scanf("%d", &m_cnt_star);
		if (m_cnt_star > 0)
		{
			have_nxt = true;
			memset(m_have_star, 0, sizeof(m_have_star));
			for (int i = 0; i < m_cnt_star; i++)
			{
				scanf("%d %d %d", &m_star[i].x, &m_star[i].y, &m_star[i].bright);
				m_have_star[coorMap(m_star[i].x)][coorMap(m_star[i].y)] = true;
				m_star_no[coorMap(m_star[i].x)][coorMap(m_star[i].y)] = i;
			}
		}
		return have_nxt;
	}
	bool have_star(int x, int y)
	{
		bool have;
		if (x > COOR_BOUND || x < -COOR_BOUND || y > COOR_BOUND || y < -COOR_BOUND)
		{
			have = false;
		}
		else
		{
			have = m_have_star[coorMap(x)][coorMap(y)];
		}
		return have;
	}
	Star star(int i)
	{
		return m_star[i];
	}
	Star star(int x, int y)
	{
		return m_star[m_star_no[coorMap(x)][coorMap(y)]];
	}
	int cnt_star()
	{
		return m_cnt_star;
	}
};

struct Occur
{
	Star left_low, right_low, right_high, left_high;
};

int occurCmp(const void *occur1, const void *occur2)
{
	Occur *p1 = (Occur *)occur1;
	Occur *p2 = (Occur *)occur2;
	int res = starCmp(&p1->left_low, &p2->left_low);
	if (res == 0)
	{
		res = starCmp(&p1->right_low, &p2->right_low);
	}
	if (res == 0)
	{
		res = starCmp(&p1->right_high, &p2->right_high);
	}
	if (res == 0)
	{
		res = starCmp(&p1->left_high, &p2->left_high);
	}
	return res;
}
Occur m_occur[MAX_OCCUR];

struct Soln
{
	int m_cnt_sketch, m_cnt_occur;
	Constel m_sketch, m_brightest;
	Map m_map;

	Constel checkOccur(Star occur_star1, Star occur_star2)
	{
		int sinUp, cosUp, down;
		getAngle(m_sketch.star(0), m_sketch.star(1), occur_star1, occur_star2, sinUp, cosUp, down);
		Constel occur_constel;
		occur_constel.init();
		occur_constel.addStar(occur_star1);
		occur_constel.addStar(occur_star2);
		for (int i = 2; i < m_sketch.cnt_star(); i++)
		{
			Star oldStar = m_sketch.star(i);
			oldStar.x = occur_star1.x + (oldStar.x - m_sketch.star(0).x);
			oldStar.y = occur_star1.y + (oldStar.y - m_sketch.star(0).y);
			Star star_new = rotate(occur_star1, oldStar, sinUp, cosUp, down);
			if (m_map.have_star(star_new.x, star_new.y))
			{
				star_new.bright = m_map.star(star_new.x, star_new.y).bright;
				occur_constel.addStar(star_new);
			}
			else
			{
				occur_constel.init();
				break;
			}
		}
		return occur_constel;
	}
	void dealWithOneStar()
	{
		m_cnt_occur = m_map.cnt_star();
		Star brightest;
		brightest = m_map.star(0);
		for (int i = 1; i < m_cnt_occur; i++)
		{
			if (m_map.star(i).bright > brightest.bright)
			{
				brightest = m_map.star(i);
			}
		}
		m_brightest.init();
		m_brightest.addStar(brightest);
	}
	inline void getAngle(Star sketchStar1, Star sketchStar2, Star occur_star1, Star occur_star2, int &sinUp, int &cosUp, int &down)
	{
		int oldX = sketchStar2.x - sketchStar1.x;
		int oldY = sketchStar2.y - sketchStar1.y;
		int newX = occur_star2.x - occur_star1.x;
		int newY = occur_star2.y - occur_star1.y;
		sinUp = oldX * newY - newX * oldY;
		cosUp = oldX * newX + oldY * newY;
		down = oldX * oldX + oldY * oldY;
	}
	void removeRepeat()
	{
		qsort(m_occur, m_cnt_occur, sizeof(Occur), occurCmp);
		int oldOccurCnt = m_cnt_occur;
		int i = 0;
		while (i < oldOccurCnt - 1)
		{
			int j = i + 1;
			while (j < oldOccurCnt && occurCmp(&m_occur[i], &m_occur[j]) == 0)
			{
				m_cnt_occur--;
				j++;
			}
			i = j;
		}
	}
	inline Star rotate(Star center, Star old, int sinUp, int cosUp, int down)
	{
		Star res;
		int relativeX = old.x - center.x;
		int relativeY = old.y - center.y;
		int xUp = relativeX * cosUp - relativeY * sinUp;
		int yUp = relativeX * sinUp + relativeY * cosUp;
		if (xUp % down == 0 && yUp % down == 0)
		{
			res.x = center.x + xUp / down;
			res.y = center.y + yUp / down;
		}
		else
		{
			res.x = COOR_BOUND + 1;
			res.y = COOR_BOUND + 1;
		}
		return res;
	}
	inline int starDis(Star star1, Star star2)
	{
		return (star1.x - star2.x) * (star1.x - star2.x) + (star1.y - star2.y) * (star1.y - star2.y);
	}
	void toOccur(Constel &constel, Occur &occur)
	{
		occur.left_low = constel.star(0);
		occur.right_low = constel.star(0);
		occur.right_high = constel.star(0);
		occur.left_high = constel.star(0);
		for (int i = 1; i < constel.cnt_star(); i++)
		{
			Star current = constel.star(i);
			if (current.x < occur.left_low.x || current.x == occur.left_low.x && current.y < occur.left_low.y)
			{
				occur.left_low = current;
			}
			if (current.y < occur.right_low.y || current.y == occur.right_low.y && current.x > occur.right_low.x)
			{
				occur.right_low = current;
			}
			if (current.x > occur.right_high.x || current.x == occur.right_high.x && current.y > occur.right_high.y)
			{
				occur.right_high = current;
			}
			if (current.y > occur.left_high.y || current.y == occur.left_high.y && current.x < occur.left_high.x)
			{
				occur.left_high = current;
			}
		}
	}

public:
	bool input()
	{
		bool have_nxt = m_map.input();
		if (have_nxt)
		{
			scanf("%d", &m_cnt_sketch);
		}
		return have_nxt;
	}
	bool inputConstel()
	{
		bool have_nxt = false;
		if (m_cnt_sketch > 0)
		{
			have_nxt = true;
			m_sketch.input();
			m_cnt_sketch--;
		}
		return have_nxt;
	}
	void solve()
	{
		if (m_sketch.cnt_star() == 1)
		{
			dealWithOneStar();
		}
		else if (m_sketch.cnt_star() > m_map.cnt_star())
		{
			m_cnt_occur = 0;
		}
		else
		{
			m_cnt_occur = 0;
			int max_bright = INT_MIN;
			for (int i = 0; i < m_map.cnt_star(); i++)
			{
				Star occur_star1 = m_map.star(i);
				for (int j = 0; j < m_map.cnt_star(); j++)
				{
					if (j != i)
					{
						Star occur_star2 = m_map.star(j);
						Constel occur_constel = checkOccur(occur_star1, occur_star2);
						if (occur_constel.cnt_star() > 0)
						{
							occur_constel.sort_star();
							int bright = occur_constel.bright();
							if (bright > max_bright)
							{
								max_bright = bright;
								m_brightest = occur_constel;
							}
							toOccur(occur_constel, m_occur[m_cnt_occur]);
							m_cnt_occur++;
						}
					}
				}
			}
			removeRepeat();
		}
	}
	void output()
	{
		printf("%s occurs %d time(s) in the map.\n", m_sketch.name(), m_cnt_occur);
		if (m_cnt_occur > 0)
		{
			printf("Brightest occurrence: ");
			m_brightest.print_constel();
		}
	}
};

int main()
{
	Soln soln;
	int mapCnt = 1;
	while (soln.input())
	{
		printf("Map #%d\n", mapCnt);
		while (soln.inputConstel())
		{
			soln.solve();
			printf("\n");
			soln.output();
		}
		printf("-----\n");
		mapCnt++;
	}
	return 0;
}
