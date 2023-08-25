/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 */
#include <bits/stdc++.h>
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> // T -> (can be integer, float or pair of int etc.)
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ordered_set<int>st ;
	st.insert(5) ;
	st.insert(2) ;
	st.insert(1) ;
	st.insert(3) ;
	st.insert(4) ;
	cout << *st.find_by_order(0) << endl ; // start from 0 -> st.size() - 1
	cout << st.order_of_key(4) << endl ;
}
