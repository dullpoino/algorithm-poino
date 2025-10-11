#pragma once
#include<algorithm-poino.hpp>

/**********************************************************
テスト用
**********************************************************/
////////////////////////////////////////////////////////////////

ll solve()
{
    chrono::system_clock::time_point start, end;

    start = chrono::system_clock::now();
    // ここで実行↓
    
    // ここで実行↑
    end = chrono::system_clock::now();
    auto time = end - start;

    auto msec = chrono::duration_cast<chrono::milliseconds>(time).count();

    return msec;
}

void calcTime(ll loops, ll time_limit)
{
    ll total_time = 0;
    rep(i, 0, loops) {
        ll ret = solve();

        // TLE検出
        if (ret > time_limit) {
            outL("TLE:", ret, ">", time_limit);
            return;
        }

        total_time += ret;
    }
    outL(total_time / loops, "msec");
}

////////////////////////////////////////////////////////////////

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ////////////////////////////////////////////////////////////

    //calcTime(10000000, INF);

    return 0;
}
