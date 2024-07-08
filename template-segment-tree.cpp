class SegmentTree{
    public:
    int len;
    vector<int> seg;
    SegmentTree(int n) {
        len=n;
        seg.resize(4*n+1);
    }
    
    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low==high) {
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind]=max(seg[2*ind+1], seg[2*ind+2]); 
    }
    void build(vector<int>&arr) {
        build(0, 0, v.size()-1, arr);
        return;
    }

    int query(int ind, int low, int high, int l, int r)
    {
        if (low>=l && high<=r) return seg[ind];
        if (high<l || low>r) return INT64_MIN;
        int mid=(low+high)/2;
        int left=query(2*ind+1, low, mid, l, r);
        int right=query(2*ind+2, mid+1, high, l, r);
        return max(left, right);
    }
    int query(int l, int r) {
        return query(0, 0, len-1, l, r);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low==high) {
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if (i<=mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
    }
    void update(int i, int val) {
        update(0, 0, len-1, i, val);
        return;
    }
};