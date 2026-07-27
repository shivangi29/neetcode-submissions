class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> hash(26);
        for(int i = 0 ; i < order.size(); i++)
            hash[order[i] - 'a'] = i;
        for(int i = 0; i <words.size()-1;i++) {
            int n1 = words[i].size(), n2 = words[i+1].size();
            int j=0;
            string w1 =  words[i], w2=words[i+1];
            while(j<n1 && j<n2) {
                if(hash[w1[j]-'a'] > hash[w2[j]-'a'])
                    return false;
                else if(hash[w1[j]-'a'] < hash[w2[j]-'a'])
                    break;
                j++;
            }
            if(j < n1 && j == n2)
                return false;
        }
        return true;
    }
};