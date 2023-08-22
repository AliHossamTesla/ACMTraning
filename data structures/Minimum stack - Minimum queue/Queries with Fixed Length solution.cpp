#include <bits/stdc++.h>
// Queries with Fixed Length - HackerRank - https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
// written by : Tesla
// in 6:31Am 22/8/2023
// The blessings of God to the Prophet Muhammad
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY queries
 */
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
vector<int> solve(vector<int> arr, vector<int> queries) {
	vector<int>ans ;
	int Q = queries.size() ;
	for(int i = 0 ; i < Q ; i ++){
		int mn = INT_MAX ;
		int n = queries[i] ;
		Queue<int>QU ;
		int j ;
		for(j = 0 ; j < n ; j ++)
			QU.add(arr[j]) ;
		mn = min(QU.maximum(),mn);
		for(;j < (int)arr.size() ; j ++){
			QU.remove() ;
			QU.add(arr[j]) ;
			mn = min(QU.maximum(),mn);
		}
		ans.push_back(mn) ;
	}
	return ans ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = solve(arr, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
