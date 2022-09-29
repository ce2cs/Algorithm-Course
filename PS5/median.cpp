#include <queue>
#include <iostream>

using namespace std;

class MedianHeap {
public:
    unique_ptr<priority_queue<int, vector<int>>> max_heap;
    unique_ptr<priority_queue<int, vector<int>, greater<int>>> min_heap;

    void Build(vector<int> &S) {
        Find_Median(S, 0, S.size() - 1);
        vector<int> smaller(S.begin(), S.begin() + (S.size() + 1) / 2);
        vector<int> larger(S.begin() + (S.size() + 1) / 2, S.end());
        max_heap = make_unique<priority_queue<int, vector<int>>>(smaller.begin(), smaller.end());
        min_heap = make_unique<priority_queue<int, vector<int>, greater<int>>>(larger.begin(), larger.end());
    }
    
    void Insert(int num) {
        if (max_heap->empty()) {
            max_heap->push(num);
            return;
        }
        if (num > max_heap->top()) {
            min_heap->push(num);
        } else {
            max_heap->push(num);
        } if (min_heap->size() > max_heap->size()) {
            max_heap->push(min_heap->top());
            min_heap->pop();
        }
        if (max_heap->size() > min_heap->size() + 1) {
            min_heap->push(max_heap->top());
            max_heap->pop();
        }
    }
    
    int Peek() {
        return max_heap->top();
    }

    int Extract() {
        auto ans = max_heap->top();
        max_heap->pop();
        if (min_heap->size() > max_heap->size()) {
            max_heap->push(min_heap->top());
            min_heap->pop();
        }
        return ans;
    }

private:
    void Find_Median(vector<int> &nums, int start, int end) {
        if (start > end) {
            return;
        }
        int left = start, right = end, curr = start, pivot = nums[start];
        while (curr < right) {
            if (nums[curr] < pivot) {
                swap(nums[left ++ ], nums[curr ++ ]);
            } else if (nums[curr] > pivot) {
                swap(nums[curr], nums[ right -- ]);
            } else {
                curr ++;
            }
        }
        if (right > nums.size() / 2) {
            Find_Median(nums, start, right - 1);
        } else if (right < nums.size() / 2) {
            Find_Median(nums, right + 1, end);
        }
        return;
    }
};

int main() {
    MedianHeap mp;
    vector<int> s{3, 8, -2, 5, 9, 5, -1, -10};
    mp.Build(s);
    // supposed to be 3
    cout << mp.Peek() << endl;
    mp.Insert(-6);
    mp.Insert(5);
    mp.Insert(7);
    // supposed to be 5
    cout << mp.Peek() << endl;

    // supposed to be 5
    cout << mp.Extract() << endl;
    // supposed to be 3
    cout << mp.Extract() << endl;
    // supposed to be 5
    cout << mp.Peek() << endl;
    // supposed to be 5
    cout << mp.Extract() << endl;
    // supposed to be -1
    cout << mp.Extract() << endl;
    // supposed to be 5
    cout << mp.Extract() << endl;
    // supposed to be -2
    cout << mp.Extract() << endl;
    mp.Insert(0);
    // supposed to be 0;
    cout << mp.Extract() << endl;
    return 0;
}
