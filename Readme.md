**TRIE**
----

![](https://github.com/LIADN7/TRIE-on-C/blob/master/img/TRIE.png)


This program produces a tree which is obtained from a text file.

**Functions in the program:**
----

* node* newNode(char c):
  
  Builds a new leaf in the TRIE tree, return a new node. --> O(1)


* void insert(node *head, char* str):
  
  Inserts a new word into TRIE. --> O(n) -  n = length of the word


* void display(node *root, char str[], int level):
  
  Displays all the words in TRIE and how many times they appeared (in dictionary order). --> O(n*logn) n = number of nodes


* void displayR(node *root, char str[], int level):
  
  Displays all the words in TRIE and how many times they appeared (in dictionary order from end to beginning). --> O(n*logn) n = number of nodes.


* void trieFree(node *root):
  
  Releases all memory from the TRIE. --> O(n) n = number of nodes.



***

<img src="https://github.com/LIADN7/TRIE-on-C/blob/master/img/Trie.png" width=50% height=50%>


**Program process:**
----
1) Receives a file by reed direction.
2) Puts all the words in TRIE.
3) Displays all words in alphabetical order or from end to beginning (if argc[1] = 'r' then from end to beginning else alphabetical).
4) Releases all memory from the TRIE.

***

 * [@author liadn7](https://github.com/LIADN7)
 * [@author avielc11](https://github.com/avielc11)
