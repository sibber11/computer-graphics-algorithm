#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;
};

const int X = 20;
const int Y = 100;

bool a[X][Y] = {0};

void drawLine(Point start_point, Point end_point)
{

    float del_x = end_point.x - start_point.x;
    // cout << del_x << endl;
    float del_y = end_point.y - start_point.y;
    // cout << del_y << endl;
    int steps = max(abs(del_x), abs(del_y));
    // cout << steps << endl;

    float x_inc = del_x / steps;
    // cout << x_inc << endl;
    float y_inc = del_y / steps;
    // cout << y_inc << endl;

    float x_cur = start_point.x;
    float y_cur = start_point.y;

    for (int i = 0; i < steps; i++)
    {
        x_cur += x_inc;
        y_cur += y_inc;
        a[(int)x_cur][(int)y_cur] = 1;
    }
}

void drawLineSeries(vector<Point> series)
{
    Point start = series.front(), end;

    for (int i = 1; i < series.size(); i++)
    {
        end = series[i];
        drawLine(start, end);
        start = end;
    }
}

int main()
{
    vector<Point> series;
    series.push_back({10,2});
    series.push_back({12,8});
    series.push_back({10,14});
    series.push_back({4,2});
    series.push_back({2,8});
    series.push_back({4,14});

    drawLineSeries(series);

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (a[i][j])
            {
                cout << ".";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    cout << "working" << endl;
    return 0;
}
