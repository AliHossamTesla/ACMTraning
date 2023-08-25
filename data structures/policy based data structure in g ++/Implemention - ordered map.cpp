/* The blessings of God to the Prophet Muhammad
 * Written by: @Tesla
 * At 12:48pm on 25/8/2023 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename Key, typename Value>
using ordered_map_pbds = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	// Define your ordered map using PBDS
	ordered_map_pbds<string, int> myOrderedMap;

	// Insert elements using insert function
	myOrderedMap["apple"] = 3;
	myOrderedMap["banana"] = 5;
	myOrderedMap["cherry"] = 2;

	// Access values using keys with find function
	auto bananaIterator = myOrderedMap.find("banana");
	if (bananaIterator != myOrderedMap.end()) {
		cout << "Number of bananas: " << bananaIterator->second << endl;
	}

	// Find the order of a specific key
	cout << "Order of apple: " << myOrderedMap.order_of_key("apple") << endl;

	// Find the k-th element
	auto secondElement = myOrderedMap.find_by_order(1);
	if (secondElement != myOrderedMap.end()) {
		cout << "2nd element: " << secondElement->first << ": " << secondElement->second << endl;
	}

	// Iterate through the ordered map
	for (const auto& pair : myOrderedMap) {
		cout << pair.first << ": " << pair.second << endl;
	}

	return 0;
}
