class MyHashSet {
    bool set[(int)1e7];
public:
    MyHashSet() {
        memset(set,0,sizeof(set));
    }
    
    void add(int key) {
        set[key] = 1;
    }
    
    void remove(int key) {
        set[key] = 0;
    }
    
    bool contains(int key) {
        return set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */