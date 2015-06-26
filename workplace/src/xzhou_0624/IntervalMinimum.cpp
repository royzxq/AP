/**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */

     // just the application of segment tree 
    struct SegmentTree{
        int start, end, min;
        SegmentTree * left, *right;
        SegmentTree(int start, int end){
            this -> start = start;
            this -> end = end;
            // this -> min = min;
            left = right = nullptr;
        }
    } ;
    
    // the similar building process as before 
    SegmentTree * build( int start, int end, vector<int> &A){
        if(end < start) return nullptr;
        SegmentTree * root = new SegmentTree(start, end);
        int mid = (start + end) / 2;
        if(start == end){
            root-> min = A[start];
            return root;
        }
        else{
            root -> left = build(start,mid,A);
            root -> right = build(mid+1, end, A);
        }
        root -> min = min(root->left->min, root->right->min);
        return root;
    }

    // excact the same query process as queryI
    int query(SegmentTree * root, int start, int end){
        if(start == root-> start && end == root->end) return root->min;  

        // the boundry of left leaf and right leaf
        int mid = (root->start + root->end) / 2;
    
        // if query interval is in the left
        if(end <= mid) return query(root->left, start, end);
    
        // the query interval is in the right; 
        else if(start > mid){
            return query(root->right,start,end);
        }
        else{
    
            // the query interval is in between, so take the maximum of left and right
            return min(query(root->left,start,mid), query(root->right,mid+1,end));
        }
            
    }

    
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        int start = 0, end = A.size()-1;
        SegmentTree * root = build(start,end,A);
        vector<int> res;
        for(auto q : queries){
            res.push_back(query(root,q.start,q.end));
        }
        return res;
    }