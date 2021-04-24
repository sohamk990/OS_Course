#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

void check(int status)
{
    if(status != 0)
    {
        printf("System Call Failed! \n");
        exit(0);
    }
}


int main()
{
    struct rlimit limit;
    int res;

    //Printing the limits
    res = getrlimit(RLIMIT_CORE, &limit);
    check(res);
    printf("Soft limit on maximum size of core file: %ld\n", limit.rlim_cur);
    printf("Hard limit on maximum size of core file: %ld\n", limit.rlim_max);

    // changing the soft-limit for the maximum size of core file from 0 to 1
    limit.rlim_cur = 1;
    res = setrlimit(RLIMIT_CORE, &limit);
    check(res);
    
    //Printing the limits
    res = getrlimit(RLIMIT_CORE, &limit);
    check(res);
    printf("New Soft limit on maximum size of core file: %ld\n", limit.rlim_cur);
    printf("New Hard limit on maximum size of core file: %ld\n", limit.rlim_max);

    return 0;
}