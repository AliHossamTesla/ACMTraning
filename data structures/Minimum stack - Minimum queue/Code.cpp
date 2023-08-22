/*
 * Minimum stack / Minimum queue
 * source : https://cp-algorithms.com/data_structures/stack_queue_modification.html
 */
#include <bits/stdc++.h>
using namespace std ;
template <typename T>
class Stack{
public:
	void add(T new_elem ){
		T new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
		st.push({new_elem, new_min});
	}
	T remove(){
		T removed_element = st.top().first;
		st.pop();
		return removed_element ;
	}
	T minimum (){
		T mn = st.top().second;
		return mn ;
	}
private:
	stack<pair<int, int>> st;
};
template <typename T>
class Queue{
private:
	stack<pair<T, T>> s1, s2;
public:
	T minimum (){
		T mn ;
		if (s1.empty() || s2.empty())
			mn = s1.empty() ? s2.top().second : s1.top().second;
		else
			mn = min(s1.top().second, s2.top().second);
		return mn ;
	}
	void add(T new_element){
		T minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
		s1.push({new_element, minimum});
	}
	T remove(){
		if (s2.empty()) {
			while (!s1.empty()) {
				T element = s1.top().first;
				s1.pop();
				T minimum = s2.empty() ? element : min(element, s2.top().second);
				s2.push({element, minimum});
			}
		}
		T remove_element = s2.top().first;
		s2.pop();
		return remove_element ;
	}
};
int main() {
	Stack<int>w ;
	w.add(5) ;
	w.add(3) ;
	w.add(2) ;
	w.add(7) ;
	w.add(1) ;
	cout << w.remove() << endl ;
	cout << w.minimum()  << endl ;
	cout << endl ;
	Queue<int>Q ;
	Q.add(0) ;
	Q.add(3) ;
	Q.add(2) ;
	Q.add(7) ;
	Q.add(1) ;
	cout << Q.remove() << endl ;
	cout << Q.minimum()  << endl ;
	return 0;
}
