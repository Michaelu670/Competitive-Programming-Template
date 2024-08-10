/*
Using powershell
Usage:  1. Compile (g++ create_snippet.cpp -o create_snippet)
        2. Use it on template files (cat "filename" | .\create_snippet "Snippet Full Name" "Snippet Shortcut" | clip)
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

const int MOD = 1000000007;
//const int MOD = 998244353;

const string TAB = "    "; // 4x space 


int32_t main(int32_t argc, char* argv[])
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string snippetFullName;
    string snippetShortcut;

    if (argc == 2) {
        snippetFullName = snippetShortcut = argv[1];
    }
    if (argc == 3) {
        snippetFullName = argv[1];
        snippetShortcut = argv[2];
    }

    cout << TAB << "\"" << snippetFullName << "\": {\n";
    cout << TAB << TAB << "\"scope\": \"cpp\",\n";
    cout << TAB << TAB << "\"prefix\": [\n";
    cout << TAB << TAB << TAB << "\"" << snippetShortcut << "\"\n";
    cout << TAB << TAB << "],\n";
    cout << TAB << TAB << "\"body\": [\n";



    string s;

    while (getline(cin, s)) {
        s = regex_replace(s, regex("\""), "\\\"");
        cout << TAB << TAB << TAB << "\"" << s << "\",\n";
    }

    
    cout << TAB << TAB << "],\n";
    cout << TAB << "},\n";
    return 0;
}
