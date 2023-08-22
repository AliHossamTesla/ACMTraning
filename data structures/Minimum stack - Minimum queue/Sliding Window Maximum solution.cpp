// written by : Tesla
// in 9:42pm 22/8/2023
class Solution {
public:
    template <typename T>
    class Queue{
    private:
        stack<pair<T, T>> s1, s2;
    public:
        T maximum (){
            T mx ;
            if (s1.empty() || s2.empty())
                mx = s1.empty() ? s2.top().second : s1.top().second;
            else
                mx = max(s1.top().second, s2.top().second);
            return mx ;
        }
        void add(T new_element){
            T mx = s1.empty() ? new_element : max(new_element, s1.top().second);
            s1.push({new_element, mx});
        }
        T remove(){
            if (s2.empty()) {
                while (!s1.empty()) {
                    T element = s1.top().first;
                    s1.pop();
                    T mx = s2.empty() ? element : max(element, s2.top().second);
                    s2.push({element, mx});
                }
            }
            T remove_element = s2.top().first;
            s2.pop();
            return remove_element ;
        }
    };
    vector<int> maxSlidingWindow(vector<int>&v, int k) {
        vector<int>ans ;
        int n = v.size() , i = 0 ;
        Queue<int>Q ;
        for(;i < k ; i ++)
            Q.add(v[i]) ;
        ans.push_back(Q.maximum()) ;
        for(;i < n ; i ++){
            Q.remove() ;
            Q.add(v[i]) ;
            ans.push_back(Q.maximum()) ;
        }
        return ans;
    }
};