#include <iostream>
#include <random>
//给一个数组a,长度为n
//输出avg（l,r）中的最大值

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        typedef struct node{
            int date;
            struct Node *next = nullptr;
        }Node;

        Node *head = nullptr;
        Node *p = nullptr;
        head -> next = p;
        for(int i = 0;i < m;i++)
        {
            Node *q = nullptr;
            q->date = nums1[i];
            q->next = p;
            head -> next = q;
        }
    }
};

int main() {
    return 0;
}