#include <bits/stdc++.h>

using namespace std;

const int nr_chars_max = 15, nr_items_max = 200;

struct item_name
{
	char name_[nr_chars_max + 1];
	bool operator<(const item_name &itn) const
  {
    return strcmp(name_, itn.name_) < 0;
  }
	bool operator==(const item_name &itn) const
  {
    return !strcmp(name_, itn.name_);
  }
};

struct item
{
	bool deleted_;
	double cost_, price_;
	int in_stock_;
};

int main()
{
	map<item_name, item> items;
	char activity[nr_chars_max + 1];
	item_name itn;
	int quantity;
	double profit = 0.0;
	while (scanf("%s", activity) != EOF && activity[0] != '*')
	{
		switch (activity[0])
		{
		case 'n':
		{
			item it;
			scanf("%s %lf %lf", itn.name_, &it.cost_, &it.price_);
			it.deleted_ = false, it.in_stock_ = 0;
			items[itn] = it;
		}
		break;
		case 'b':
			scanf("%s %d", itn.name_, &quantity);
			items[itn].in_stock_ += quantity;
			break;
		case 's':
		{
			scanf("%s %d", itn.name_, &quantity);
			item &it = items[itn];
			it.in_stock_ -= quantity;
			profit += (it.price_ - it.cost_) * quantity;
		}
		break;
		case 'd':
		{
			scanf("%s", itn.name_);
			item &it = items[itn];
			it.deleted_ = true;
			profit -= it.cost_ * it.in_stock_;
			it.in_stock_ = 0;
		}
		break;
		default:// report
			double total = 0.0;
			puts("                  INVENTORY REPORT");
			puts("Item Name     Buy At      Sell At      On Hand        Value");
			puts("---------     ------      -------      -------        -----");
			for (map<item_name, item>::const_iterator ii = items.begin(), ie = items.end();
					 ii != ie; ++ii)
			{
				const item &it = ii->second;
				if (!it.deleted_)
				{
					double value = it.cost_ * it.in_stock_;
					printf("%-10s %9.2lf %12.2lf %12d %12.2lf\n",
								 ii->first.name_, it.cost_, it.price_, it.in_stock_, value);
					total += value;
				}
			}
			puts("------------------------");
			printf("Total value of inventory                       %12.2lf\n", total);
			printf("Profit since last report                       %12.2lf\n\n", profit);
			profit = 0.0;
			break;
		}
	}
	return 0;
}
