#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::vector;

int binary_search(const vector<int> &a, int x)
{
  int left = 0, right = (int)a.size() - 1;
  // write your code here
  int mid = (right + (left - right) / 2);

  while (left <= right)
  {

    if (x < a[mid])
    {
      left = 0;
      right = mid - 1;
    }
    else if (x > a[mid])
    {
      left = mid + 1;
    }
    else
    {
      if (a[mid - 1] == x)
      {

        while (true)
        {
          if (a[mid - 1] != x)
          {
            return mid;
          }
          mid--;
        }
      }
      // else if (a[mid + 1] == x)
      // {
      //   while (true)
      //   {
      //     if (a[mid + 1] != x)
      //     {
      //       return mid;
      //     }

      //     mid++;
      //   }
      // }
      else
      {
        return mid;
      }
    }
    mid = (right + (left - right) / 2);
  }

  return -1;
}
// cout<<"here";


int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i)
  {
    // replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  // int x = 7;
  // vector<int> a{3 ,4 ,5 ,6, 7, 7, 7, 8};
  // cout << binary_search(a, x);
}