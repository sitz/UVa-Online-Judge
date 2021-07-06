#include <bits/stdc++.h>

using namespace std;

double d(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double m(double x1, double y1, double x2, double y2)
{
	return (y1 - y2) / (x1 - x2);
}

double ix(double x1, double y1, double x2, double y2, double m1, double m2)
{
	return (m1 * x1 - m2 * x2 + y2 - y1) / (m1 - m2);
}

int main()
{
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		double xA, yA, xB, yB, xC, yC;
		scanf("%lf%lf%lf%lf%lf%lf", &xA, &yA, &xB, &yB, &xC, &yC);
		double AB, AC, BC, P;
		AB = d(xA, yA, xB, yB);
		AC = d(xA, yA, xC, yC);
		BC = d(xB, yB, xC, yC);
		P = AB + AC + BC;
		double pAB, pAC, pBC;
		pAB = P / 2 - AC;
		pAC = P / 2 - BC;
		pBC = P / 2 - AB;
		if (pAB < 0 || pAC < 0 || pBC < 0)
		{
			printf("Case %d: ERROR\n", t);
		}
		else
		{
			bool fAB = false, fAC = false, fBC = false;
			double mAB, mAC, mBC, iAB, iAC, iBC;
			if (xA != xB)
			{
				mAB = m(xA, yA, xB, yB);
			}
			else
			{
				fAB = true;
			}
			if (xA != xC)
			{
				mAC = m(xA, yA, xC, yC);
			}
			else
			{
				fAC = true;
			}
			if (xB != xC)
			{
				mBC = m(xB, yB, xC, yC);
			}
			else
			{
				fBC = true;
			}
			if (!fAB)
			{
				iAB = yA - mAB * xA;
			}
			if (!fAC)
			{
				iAC = yA - mAC * xA;
			}
			if (!fBC)
			{
				iBC = yB - mBC * xB;
			}
			double aAB, aAC, aBC;
			if (!fAB)
			{
				aAB = atan(mAB);
				if (aAB > M_PI / 2)
				{
					aAB = M_PI / 2 - aAB;
				}
			}
			if (!fAC)
			{
				aAC = atan(mAC);
				if (aAC > M_PI / 2)
				{
					aAC = M_PI / 2 - aAC;
				}
			}
			if (!fBC)
			{
				aBC = atan(mBC);
				if (aBC > M_PI / 2)
				{
					aBC = M_PI / 2 - aBC;
				}
			}
			double xAB, xAC, xBC;
			if (!fAB)
			{
				if (xA < xB)
				{
					xAB = xA + pAB * cos(aAB);
				}
				else
				{
					xAB = xA - pAB * cos(aAB);
				}
			}
			else
			{
				xAB = xA;
			}
			if (!fAC)
			{
				if (xC < xA)
				{
					xAC = xC + pAC * cos(aAC);
				}
				else
				{
					xAC = xC - pAC * cos(aAC);
				}
			}
			else
			{
				xAC = xC;
			}
			if (!fBC)
			{
				if (xB < xC)
				{
					xBC = xB + pBC * cos(aBC);
				}
				else
				{
					xBC = xB - pBC * cos(aBC);
				}
			}
			else
			{
				xBC = xB;
			}
			double yAB, yAC, yBC;
			if (!fAB)
			{
				yAB = xAB * mAB + iAB;
			}
			else
			{
				if (yA > yB)
				{
					yAB = yA - pAB;
				}
				else
				{
					yAB = yA + pAB;
				}
			}
			if (!fAC)
			{
				yAC = xAC * mAC + iAC;
			}
			else
			{
				if (yC > yA)
				{
					yAC = yC - pAC;
				}
				else
				{
					yAC = yC + pAC;
				}
			}
			if (!fBC)
			{
				yBC = xBC * mBC + iBC;
			}
			else
			{
				if (yB > yC)
				{
					yBC = yB - pBC;
				}
				else
				{
					yBC = yB + pBC;
				}
			}
			bool f_A = false, f_B = false, f_C = false;
			double m_A, m_B, m_C, i_A, i_B, i_C;
			if (xA != xBC)
			{
				m_A = m(xA, yA, xBC, yBC);
				i_A = yA - m_A * xA;
			}
			else
			{
				f_A = true;
			}
			if (xB != xAC)
			{
				m_B = m(xB, yB, xAC, yAC);
				i_B = yB - m_B * xB;
			}
			else
			{
				f_B = true;
			}
			if (xC != xAB)
			{
				m_C = m(xC, yC, xAB, yAB);
				i_C = yC - m_C * xC;
			}
			else
			{
				f_C = true;
			}
			double x_AB, x_AC, x_BC, y_AB, y_AC, y_BC;
			if (!f_A && !f_B)
			{
				x_AB = ix(xA, yA, xB, yB, m_A, m_B);
				y_AB = m_A * x_AB + i_A;
				printf("Case %d: %.6lf %.6lf\n", t,x_AB,y_AB);
			}
			else if (!f_A && !f_C)
			{
				x_AC = ix(xA, yA, xC, yC, m_A, m_C);
				y_AC = m_C * x_AC + i_C;
				printf("Case %d: %.6lf %.6lf\n", t,x_AC,y_AC);
			}
			else if (!f_B && !f_C)
			{
				x_BC = ix(xB, yB, xC, yC, m_B, m_C);
				y_BC = m_B * x_BC + i_B;
				printf("Case %d: %.6lf %.6lf\n", t,x_BC,y_BC);
			}
			else
			{
				printf("Case %d: ERROR\n", t);
			}
		}
	}
	return 0;
}
