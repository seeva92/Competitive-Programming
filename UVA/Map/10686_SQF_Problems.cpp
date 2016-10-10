#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

map<string, pair<int,int> > catMap;
map<string, set<string> >  myMap;
vector<string> vec;
vector<string> ansVec;
set<string> mySet;

void init()
{
    catMap.clear();
    myMap.clear();
    vec.clear();
    ansVec.clear();
    mySet.clear();
}

void getWords(string str)
{
    string word = "";
    for(int x=0; x<str.size(); x++)
    {
        if(isalpha(str[x]))
           word += str[x];
        else if(word.size() != 0)
        {
            mySet.insert(word);
            word = "";
        }
    }
    if(word.size() != 0)
       mySet.insert(word);
}

void getAns()
{
    string tmp;
    int cont;
    for(int x=0; x<vec.size(); x++)
    {
        tmp = vec[x];
        set<string> cSet = myMap[tmp];
        cont = 0;

        for(set<string>::iterator it = mySet.begin(); it!=mySet.end(); it++)
        {
            if(cSet.find(*it) != cSet.end())
               cont++;
        }

        if(cont >= catMap[tmp].second)
           ansVec.push_back(tmp);
    }
}

int main()
{
    int casos, categorias, words, needed;
    string catName, str;

    scanf("%d", &casos);

    while(casos--)
    {
        init();
        scanf("%d", &categorias);
        for(int i=0; i<categorias; i++)
        {
            cin>>catName;
            vec.push_back(catName);
            scanf("%d %d", &words, &needed);
            pair<int,int> p = make_pair(words, needed);
            catMap[catName] = p;

            for(int j=0; j<words; j++)
            {
                cin>>str;
                myMap[catName].insert(str);
            }
        }
        getline(cin, str);//trash
        while(getline(cin, str))
        {
            if(str.size() == 0)
               break;
            getWords(str);
        }
        getAns();

        if(ansVec.size() == 0)
           printf("SQF Problem.\n");
        else
        {
            for(int g=0; g<ansVec.size() - 1; g++)
            {
                cout<<ansVec[g]<<',';
            }
            cout<<ansVec[ansVec.size() - 1]<<'\n';
        }
    }
return 0;
}
// #include <iostream>
// #include <cstdlib>
// #include <cstring>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <sstream>
// #include <set>
// #include <climits>
// #include <cstdio>
// #include <string>
// #include <map>
// #include <unordered_map>
// using namespace std;
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("1.txt", "r", stdin);
// 	freopen("2.txt", "w", stdout);
// #endif
// 	int n, c, w, p;
// 	string s; char str1[100], str2[100];
// 	scanf("%d", &n);
// 	while (n--) {
// 		map<string, set<string>> rmap;
// 		vector<pair<string, int>> count;
// 		scanf("%d", &c);
// 		while (c--) {
// 			scanf("%s %d %d", str1, &w, &p);
// 			count.push_back(make_pair(string(str1), p));
// 			while (w--) {
// 				scanf("%s", &str2);
// 				rmap[str2].insert(string(str1));
// 			}
// 		}
// 		// for(auto it : rmap)
// 		// cout<<it.first<<" "<<it.second<<'\n';
// 		// for(auto it: count)
// 		// cout<<it.first<<" "<<it.second<<'\n';
// 		// break;
// 		getline(cin, s);
// 		map<string, int> processed;
// 		set<string> words;
// 		string temp;
// 		while (getline(cin, s), s != "") {
// 			for (int i = 0; i < (int)s.size(); i++) {
// 				if (isalpha(s[i]))
// 					temp += s[i];
// 				else if (!temp.empty()) {
// 					words.insert(temp);
// 					temp.clear();
// 				}
// 			}
// 			if (cin.eof())
// 				break;
// 		}
// 		if (!temp.empty()) {
// 			words.insert(temp);
// 			temp.clear();
// 		}
// 		for (auto it : words) {
// 			set<string> st = rmap[it];
// 			for (auto it1 : st) {
// 				processed[it1]++;
// 			}
// 		}


// 		int i = 0;
// 		for (auto it : count) {
// 			// cout << it.first << " " << it.second << "\n";
// 			// cout << it.first << " " << processed[it.first] << '\n';
// 			if (processed[it.first] >= it.second) {
// 				if (i == 0)
// 					printf("%s", it.first.c_str());
// 				else
// 					printf(",%s", it.first.c_str());
// 				i++;
// 			}
// 		}
// 		if (i == 0)
// 			printf("SQF Problem.");
// 		if (n != 0)
// 			printf("\n");

// 	}
// }


