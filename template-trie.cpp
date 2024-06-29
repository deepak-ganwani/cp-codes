class Trie {
public:
    Trie* arr[26];
    bool end;
    // NOTE: TO USE THE BELOW COUNTERS UPDATE THE CONSTRUCTOR & THE FUNCTIONS
    // int word_end=0; // count for words ending at this instance of Trie
    // int prefix_end=0; // count for prefix's ending at this instance

    Trie() {
        for(int i=0; i<26; i++) {
            arr[i]=NULL;
        }
        end=false;
    }
    
    void insert(string word) {
        Trie* curr=this;
        for(char& ch:word){
            if(curr->arr[ch-'a']!=NULL){
                curr=curr->arr[ch-'a'];
            }else{
                Trie* child=new Trie();
                curr->arr[ch-'a']=child;
                curr=child;
            }
        }
        curr->end=true;
    }

    bool search(string word) {
        Trie* curr=this;
        for(char& ch:word) {
            if(curr->arr[ch-'a']!=NULL) curr=curr->arr[ch-'a'];
            else return false;
        }
        return curr->end;
    }

    bool starts_with(string word) {
        Trie* curr=this;
        for(char& ch:word) {
            if(curr->arr[ch-'a']!=NULL) curr=curr->arr[ch-'a'];
            else return false;
        }
        return true;
    }
};


/*

Trie Using 2D array : https://codeforces.com/blog/entry/50357

*/