class NumberContainers {
public:
    unordered_map<int, int> mp;
    unordered_map<int, set<int>> mp2;

    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(mp.find(index)!=mp.end()){
            int n = mp[index];
            mp[index]=number;
            if(mp2[n].size()==1) mp2.erase(n);
            else mp2[n].erase(index);
        }
        else{
            mp[index]=number;
        }
        mp2[number].insert(index);
    }
    
    int find(int number) {
        if(mp2.find(number)!=mp2.end()) return *mp2[number].begin();
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */