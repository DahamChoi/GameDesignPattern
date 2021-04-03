#include "ParticlePool.h"

int main()
{
    ParticlePool pool;
    pool.Create(0, 0, 1, 1, 2);
    pool.Create(0, 0, 1, 1, 3);
    pool.Create(0, 0, 1, 1, 1);
    pool.Create(0, 0, 1, 1, 6);
    pool.Create(0, 0, 1, 1, 4);
    pool.Create(0, 0, 1, 1, 2);
    pool.Create(0, 0, 1, 1, 3);
    pool.Create(0, 0, 1, 1, 4);
    pool.Create(0, 0, 1, 1, 1);

    for(int i = 0; i < 10; i++)
        pool.Animation();
}