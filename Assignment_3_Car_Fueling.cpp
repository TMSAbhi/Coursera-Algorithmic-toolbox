#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> stops)
{

    int temp_dis_count = 0;     // distance travelled after full tank
    int ref_count = 0;          // no. of refills
    int temp_tank_count = tank; // temp variable for count fuel consumption
    int temp_dist = 0;

    int i = 0;

    int fuel_left = 0;

   

    if (dist <= tank)
    {
        return 0;
    }

    while (temp_dist != dist)
    {
        temp_tank_count--;
        temp_dis_count++;
        temp_dist++;

        if (temp_dist == stops[i])
        {

            fuel_left = tank - temp_dis_count;
            if (i == stops.size() - 1)
            {
                int dis_left = dist - stops[i];
                if (dis_left <= fuel_left)
                {
                    // continue
                }
                else
                {
                    if (stops.size() == 1 and tank >= dist / 2)
                    {
                        return 1;
                    }
                    ref_count++;
                    temp_tank_count = tank; /// fuel refilled
                    temp_dis_count = 0;
                }
            }
            else
            {
                if (fuel_left >= (stops[i + 1] - stops[i]) and (i + 1) <= stops.size() - 1) // checking if the fuel left is sufficient till the next stop
                {
                    // continue travelling
                }
                else
                {
                    
                    ref_count++;
                    temp_tank_count = tank; /// fuel refilled
                    temp_dis_count = 0;
                }
            }

            i++;
        }
        
        if (temp_tank_count == 0 and temp_dist != dist) // if tank is empty and destination is not reached return -1
        {
            

            return -1;
        }
    }

    return ref_count;
}

int main()
{
        int d = 0;
        cin >> d;
        int m = 0;
        cin >> m;
        int n = 0;
        cin >> n;

        vector<int> stops(n);
        for (size_t i = 0; i < n; ++i)
            cin >> stops.at(i);

        cout << compute_min_refills(d, m, stops) << "\n";
    

    return 0;
}
