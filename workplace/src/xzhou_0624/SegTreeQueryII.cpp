/**
 *@param root, start, end: The root of segment tree and 
 *                         an segment / interval
 *@return: The count number in the interval [start, end] 
 */

 // basically the same as query I but instead of taking max, taking sum 
int query(SegmentTreeNode *root, int start, int end) {
    // write your code here
    // handle the unnormal input
    if(!root) return 0;
    if(start > root->end || end < root->start) return 0;
    if(start < root->start) start = root->start;
    if(end > root->end) end = root->end;

    
    if(start == root-> start && end == root->end){
        return root->count;
    }
    int mid = (root-> start + root-> end) / 2;
    if(end <= mid){
        return query(root->left,start,end);
    }
    else if(start > mid){
        return query(root->right,start,end);
    }
    else{
        return query(root->left, start,mid) + query(root->right,mid+1,end);
    }
}