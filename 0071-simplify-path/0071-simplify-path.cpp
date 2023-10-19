class Solution {
public:
    string simplifyPath(string path) {
        
        string ans;
        
        stack<string> st; 
        int size = path.size();
        int idx = 0;
        int cnt = 0;
        
        for(int i=0;i<size;i++)
        {
            if(path[i]=='/')
            {
                st.push(path.substr(idx, i - idx));
                idx = i;
            }
        }
        
        if(idx!=size-1)
        {
            st.push(path.substr(idx,size-idx));
        }
        
        while(st.size()!=0)
        {  
            if(st.top()=="/")
            {
                st.pop();
            }
            else if(st.top()=="/.")
            {
                st.pop();
            }
            else if(st.top()=="/..")
            {
                cnt++;
                st.pop();  
            }
            else
            {
                if(cnt==0)
                {
                    ans.insert(0,st.top());
                }
                else
                {
                    cnt--;
                }
                st.pop();
            }
        }
        
        if(ans[0]!='/')
        {
            ans.insert(0,"/");
        }
        return ans;
        
    }
        
};