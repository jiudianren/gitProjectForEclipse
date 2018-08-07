class Solution {
public:
    string longestPalindrome(string s) {


    	int size = s.size();

    	int start = 0;
    	int maxleng= 0;

        if( size ==1)
        {return s;}
        for( int i=0 ;i < size ;i ++)
        {
        	for( int j= i+1; j< size; j++)
        	{
        		int front = i;
        		int  back =j;
        		for( ; front<back;front++, back--)
        		{
        			if( s[front] != s[back] )
        				break;
        		}

        		if( front >= back && j-i+1 > maxleng)
        		{
        			start =i;
        			maxleng= j-i+1;
        		}
        	}

        }
        if(maxleng == 0)
        {
            return s.substr(0,1);
        }
        return s.substr(start,maxleng);

    }
};
