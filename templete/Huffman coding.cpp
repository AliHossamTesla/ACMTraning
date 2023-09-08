#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman tree node
struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparator function for priority queue
struct Compare {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) {
        return lhs->frequency > rhs->frequency;
    }
};

// Build Huffman tree
HuffmanNode* buildHuffmanTree(const unordered_map<char, unsigned>& freq_map) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& entry : freq_map) {
        pq.push(new HuffmanNode(entry.first, entry.second));
    }

    while (pq.size() > 1) {
        // Extract the two nodes with the minimum frequency from the priority queue
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies
        // The data value of internal nodes is not relevant, so we set it to a special value like '$'
        HuffmanNode* internal = new HuffmanNode('$', left->frequency + right->frequency);
        internal->left = left;
        internal->right = right;

        // Add the new internal node back to the priority queue
        pq.push(internal);
    }

    // The remaining node is the root of the Huffman tree
    return pq.top();
}

// Utility function to build the Huffman codes
void buildHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffman_codes) {
    if (root == nullptr)
        return;

    // If the node is a leaf node (i.e., it contains a character), store its Huffman code in the map
    if (root->data != '$') {
        huffman_codes[root->data] = code;
    }

    // Traverse left and right recursively and append '0' to the code when going left and '1' when going right
    buildHuffmanCodes(root->left, code + "0", huffman_codes);
    buildHuffmanCodes(root->right, code + "1", huffman_codes);
}

// Function to compress the input text using the Huffman codes
string compressText(const string& text, const unordered_map<char, string>& huffman_codes) {
    string compressed_text;
    for (char c : text) {
        compressed_text += huffman_codes.at(c);
    }
    return compressed_text;
}

int main() {
    string text = "this is an example for huffman encoding";
    unordered_map<char, unsigned> freq_map;

    // Count the frequency of each character in the input text
    for (char c : text) {
        freq_map[c]++;
    }

    // Build the Huffman tree
    HuffmanNode* root = buildHuffmanTree(freq_map);

    // Build the Huffman codes
    unordered_map<char, string> huffman_codes;
    buildHuffmanCodes(root, "", huffman_codes);

    // Compress the input text using the Huffman codes
    string compressed_text = compressText(text, huffman_codes);

    // Output the result
    cout << "Original text: " << text << endl;
    cout << "Compressed text: " << compressed_text << endl;

    return 0;
}
