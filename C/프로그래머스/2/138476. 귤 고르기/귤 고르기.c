#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp_desc(const void* a, const void* b) 
{
    return (*(int*)b - *(int*)a);
}

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer = 0;
    int count[10000004] = {0};
    int max_value = 0;
    
    for (size_t i = 0; i < tangerine_len; ++i)
    {
        count[tangerine[i]]++;
        if (tangerine[i] > max_value)
        {
            max_value = tangerine[i];
        }
    }
    
    int freq_arr[tangerine_len];
    int freq_len = 0;
    for (int i = 0; i <= max_value; ++i)
    {
        if (count[i] > 0)
        {
            freq_arr[freq_len++] = count[i];
        }
    }
    
    qsort(freq_arr, freq_len, sizeof(int), cmp_desc);
    
    for (int i = 0; i < freq_len; ++i) 
    {
        k -= freq_arr[i];
        answer++;
        if (k <= 0) break;
    }
    
    return answer;
}