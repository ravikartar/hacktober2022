struct Node {
    Node *link[26];
    bool flag ;
    Node() {
        for (int i = 0 ; i < 26 ; i ++) link[i] = NULL;
        flag = false;
    }

    bool contains( char c ) { return link[c - 'a']; }
    void put ( char c , Node* node) { link[c - 'a'] = node ; }
    Node* get ( char c ) { return link[c - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd () { return flag ; }


};



class Trie {
  private:
    Node* root ;
  public:
    Trie() {
        root = new Node();
    }


    void insert(string word) {
        Node* node = root ;
        for ( int i = 0 ; i < word.size() ; i++) {
            if ( !node -> contains ( word.at(i))) node -> put ( word.at(i) , new Node());
            node = node -> get ( word.at(i));
        }

        node -> setEnd();
    }

    bool search(string word) {
        Node* node = root ;
        for ( int i = 0 ; i < word.size() ; i ++) {
            if ( !node -> contains( word.at(i))) return false;
            node = node -> get ( word.at(i));

        }

        return node-> isEnd();
    }

    bool startsWith(string word) {
        Node* node = root ;
        for ( int i = 0 ; i < word.size() ; i ++) {
            if ( !node -> contains( word.at(i))) return false;
            node = node -> get ( word.at(i));
        }

        return true;
    }



};
