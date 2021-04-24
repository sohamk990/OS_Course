#include <stdio.h> 
#include <sys/resource.h> 
#include <stdlib.h>

void check(int status)
{
    if(status != 0)
    {
        printf("System Call Failed!\n");
        exit(0);
    }    
}


int main()
{
    struct rlimit limit;
    int res;

    res = getrlimit(RLIMIT_CORE, &limit);
    check(res);
    printf("Soft limit on maximum size of core file: %ld\n", limit.rlim_cur);
    printf("Hard limit on maximum size of core file: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_CPU, &limit);
    check(res);
    printf("Soft limit on process's CPU time consumption: %ld\n", limit.rlim_cur);
    printf("Hard limit on process's CPU time consumption: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_AS, &limit);
    check(res);
    printf("Soft limit on process's virtual memory: %ld\n", limit.rlim_cur);
    printf("Hard limit on process's virtual memory: %ld\n", limit.rlim_max);

    res = getrlimit(RLIMIT_NICE, &limit);
    check(res);
    printf("Soft limit on process's nice value: %ld\n", limit.rlim_cur);
    printf("Hard limit on process's nice value: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_DATA, &limit);
    check(res);
    printf("Soft limit on process's data segment: %ld\n", limit.rlim_cur);
    printf("Hard limit on process's data segment: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_LOCKS, &limit);
    check(res);
    printf("Soft limit on flocl locks + fcntl leases: %ld\n", limit.rlim_cur);
    printf("Hard limit on flocl locks + fcntl leases: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_MEMLOCK, &limit);
    check(res);
    printf("Soft limit on bytes of memory that can be locked into RAM: %ld\n", limit.rlim_cur);
    printf("Hard limit on bytes of memory that can be locked into RAM: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_MSGQUEUE, &limit);
    check(res);
    printf("Soft limit on bytes for message queues: %ld\n", limit.rlim_cur);
    printf("Hard limit on bytes for message queues: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_NPROC, &limit);
    check(res);
    printf("Soft limit on number of extant process: %ld\n", limit.rlim_cur);
    printf("Hard limit on number of extant process: %ld\n", limit.rlim_max);

    res = getrlimit(RLIMIT_NOFILE, &limit);
    check(res);
    printf("Soft limit on maximum file-descriptor number: %ld\n", limit.rlim_cur - 1);
    printf("Hard limit on maximum file-descriptor number: %ld\n", limit.rlim_max - 1);


    res = getrlimit(RLIMIT_RSS, &limit);
    check(res);
    printf("Soft limit on process's resident set: %ld\n", limit.rlim_cur);
    printf("Hard limit on process's resident set: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_RTPRIO, &limit);
    check(res);
    printf("Soft limit on real-time priority: %ld\n", limit.rlim_cur);
    printf("Hard limit on real-time priority: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_RTTIME, &limit);
    check(res);
    printf("Soft limit on process's time under real-time scheduling: %ld\n", limit.rlim_cur);
    printf("Hard limit on process's time under real-time scheduling: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_SIGPENDING, &limit);
    check(res);
    printf("Soft limit on maximum number of siganls to be queued: %ld\n", limit.rlim_cur);
    printf("Hard limit on maximum number of siganls to be queued: %ld\n", limit.rlim_max);


    res = getrlimit(RLIMIT_STACK, &limit);
    check(res);
    printf("Soft limit on maximum stack on process stack: %ld\n", limit.rlim_cur);
    printf("Hard limit on maximum stack on process stack: %ld\n", limit.rlim_max);

    return 0;
}