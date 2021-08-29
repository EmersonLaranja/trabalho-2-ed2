#include "item.h"

Item create_item(int id, double value)
{
  Item item;
  item.id = id;
  item.value = value;
  return item;
};

void show_item(Item item)
{
  printf("%d %lf\n", item.id, item.value);
}