class SnapshotArray 
{
public:
    int snap_id_ = 0;
    vector<map<int, int>> um;

    SnapshotArray(int length) 
    {
        um.resize(length);
        for (int i = 0; i < length; ++i)
            um[i][0] = 0;
    }
    
    void set(int index, int val) 
    {
        um[index][snap_id_] = val;
    }
    
    int snap() 
    {
        return snap_id_++;
    }
    
    int get(int index, int snap_id) 
    {
        if (um[index].find(snap_id) != um[index].end())
            return um[index][snap_id];
        auto curIt = --um[index].lower_bound(snap_id);
        return curIt->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */