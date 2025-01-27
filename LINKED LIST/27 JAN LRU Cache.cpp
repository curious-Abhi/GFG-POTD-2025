class LRUCache {
  private:
  struct Node{
      int key,value;
      Node* prev;
      Node* next;
      Node(int k,int v):key(k),value(v),prev(nullptr),next(nullptr){}
  };
  int capacity;
  unordered_map<int ,Node*>cache;
  Node* head;
  Node* tail;
  
  
   void addNode(Node* node){
     node->next=head->next;
     node->prev=head;
     head->next->prev=node;
     head->next=node;
  }
  void removeNode(Node* node){
      Node* prevNode=node->prev;
      Node* nextNode=node->next;
      
      prevNode->next=nextNode;
      nextNode->prev=prevNode;
  }
 
   void moveToHead(Node* node){
      removeNode(node);
      addNode(node);
  }
 
  
  Node* removeTail(){
     Node* lru=tail->prev;
     removeNode(lru);
     return lru;
 }
  
 
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap):capacity(cap) {
        // code here
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(cache.find(key)==cache.end()) return -1;
        Node* node=cache[key];
        moveToHead(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(cache.find(key)!=cache.end()){
            Node* node=cache[key];
            node->value=value;
            moveToHead(node);
        }else {
            Node* newNode=new Node(key,value);
            cache[key]=newNode;
            addNode(newNode);
            if(cache.size()>capacity){
                Node* lru=removeTail();
                cache.erase(lru->key);
                delete lru;
            }
        }
        
    }
};