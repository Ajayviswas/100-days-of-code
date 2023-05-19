int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int>>q;
        set<string>s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);
         while(!q.empty())
         {
             string word=q.front().first;
             int steps=q.front().second;
             q.pop();
             if(word==endWord)
             return steps;
             for(int i=0;i<word.size();i++)
             {
                char original=word[i];
                for(char j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(s.find(word)!=s.end())
                    {
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
             }
         }
         return 0;
    }