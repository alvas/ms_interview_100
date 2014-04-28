#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// T must be a container/class type which supports begin, end method and has
// iterator, for example container or string type.
// T1 is the data element type.
template <typename T, typename T1>
void Permutation(T &t, int idx)
{
    if (t.size() == 0)
    {
        return;
    }

    string::iterator itr = t.begin() + idx;

    if (itr == t.end())
    {
        cout << t << endl;
    }
    else
    {
        for (string::iterator itr2 = itr; itr2 != t.end(); ++itr2)
        {
            T1 tmp = *itr2;
            *itr2 = *itr;
            *itr = tmp;

            // !!pitfall!! Don't use idx++ here, otherwise, it would modify idx value.
            Permutation<T, T1>(t, idx + 1);

            tmp = *itr2;
            *itr2 = *itr;
            *itr = tmp;
        }
    }
}

void printPath(int x, vector<int> &d, vector<string> &word, vector< vector<int> > &next, vector<string> &path, vector< vector<string> > &answer)
{
    path.push_back(word[x]);

    if (d[x] == 0)
    {
        answer.push_back(path);
    }
    else
    {
        for (int i = 0; i < next[x].size(); ++i)
        {
            printPath(next[x][i], d, word, next, path, answer);
        }
    }

    path.pop_back();
}

vector< vector<string> > findLadders(string start, string end, set<string> &dict)
{
    vector< vector<string> > answer;

    if (start == end)
    {
        return answer;
    }

    dict.insert(start);
    dict.insert(end);

    vector<string> word;
    map<string, int> allWord;

    // In order to process characters of word in two dimentions, we put
    // those words into a string vector.
    // And consturct the word to index map.
    for (set<string>::iterator itr = dict.begin(); itr != dict.end(); ++itr)
    {
        word.push_back(*itr);
        allWord.insert(make_pair(*itr, allWord.size()));
    }

    // use 2D vector to save adjacent matrix
    vector< vector<int> > con;

    int n = word.size();
    int len = word[0].length();
    // resize the 2D vector
    con.resize(n);

    // build adjacent matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            for (char c = word[i][j] + 1; c <= 'z'; ++c)
            {
                char temp = word[i][j];
                word[i][j] = c;
                map<string, int>::iterator t = allWord.find(word[i]);

                if (t != allWord.end())
                {
                    con[i].push_back(t->second);
                    con[t->second].push_back(i);
                }

                word[i][j] = temp;
            }
        }
    }

    int from = allWord[start], to = allWord[end];
    // vector to save distance from end
    vector<int> d;
    d.resize(n, -1);
    d[to] = 0;
    queue<int> q;
    q.push(to);
    vector< vector<int> > next;
    next.resize(n);

    while (!q.empty())
    {
        int x = q.front(), now = d[x] + 1;

        if ((d[from] >= 0) && (now > d[from]))
        {
            break;
        }

        q.pop();

        for (int i = 0; i < con[x].size(); ++i)
        {
            int y = con[x][i];

            if (d[y] < 0)
            {
                d[y] = now;
                q.push(y);
                next[y].push_back(x);
            }
            // Special. Need to consider multiple paths merge to one node with same
            // distance.
            else if (d[y] == now)
            {
                next[y].push_back(x);
            }
        }
    }

    if (d[from] >= 0)
    {
        // pass the path vector to save the path result
        vector<string> path;
        printPath(from, d, word, next, path, answer);
    }

    return answer;
}

void search_next_reach(set<string> &reach, const set<string> &other_reach, set<string> &meet, map<string, vector<string> >& path, set<string> &dict)
{
    set<string> temp;
    reach.swap(temp);

    for (set<string>::iterator it = temp.begin(); it != temp.end(); ++it)
    {
        string s = *it;

        for (size_t i = 0; i < s.length(); ++i)
        {
            char back = s[i];

            for (s[i] = 'a'; s[i] <= 'z'; ++s[i])
            {
                if (s[i] != back)
                {
                    if (reach.count(s) == 1)
                    {
                        path[s].push_back(*it);
                    }
                    else if (dict.erase(s) == 1)
                    {
                        path[s].push_back(*it);
                        reach.insert(s);
                    }
                    else if (other_reach.count(s) == 1)
                    {
                        path[s].push_back(*it);
                        reach.insert(s);
                        meet.insert(s);
                    }
                }
            }

            s[i] = back;
        }
    }
}

void walk(vector< vector<string> > &all_path, map<string, vector<string> > kids)
{
    vector< vector<string> > temp;

    while (!kids[all_path.back().back()].empty())
    {
        all_path.swap(temp);
        all_path.clear();

        for (vector< vector<string> >::iterator itr = temp.begin(); itr != temp.end(); ++itr)
        {
            vector<string> &one_path = *itr;
            vector<string> &p = kids[one_path.back()];

            // for each node connecting to the last node in one path, we build a path
            for (vector<string>::iterator itr2 = p.begin(); itr2 != p.end(); ++itr2)
            {
                all_path.push_back(one_path);
                all_path.back().push_back(*itr2);
            }
        }
    }
}

void printFunc(string str)
{
    cout << str << " ";
}

struct printClass
{
    void operator () (string str) { cout << str << " "; }
} printObject;

vector< vector<string> > findLadders2(string start, string end, set<string> &dict)
{
    vector< vector<string> > result;

    if (dict.erase(start) == 1 && dict.erase(end) == 1)
    {
        map<string, vector<string> > kids_from_start;
        map<string, vector<string> > kids_from_end;

        set<string> reach_start;
        reach_start.insert(start);
        set<string> reach_end;
        reach_end.insert(end);

        set<string> meet;

        // build the connection graph with kids_from_start
        while (meet.empty() && !reach_start.empty() && !reach_end.empty())
        {
#ifdef DEBUG
            cout << "reach_start(" << reach_start.size() << "): ";

            for_each(reach_start.begin(), reach_start.end(), printFunc);

            cout << endl;

            cout << "reach_end(" << reach_end.size() << "): ";

            for_each(reach_end.begin(), reach_end.end(), printObject);

            cout << endl;
#endif
            if (reach_start.size() < reach_end.size())
            {
                search_next_reach(reach_start, reach_end, meet, kids_from_start, dict);
            }
            else
            {
                search_next_reach(reach_end, reach_start, meet, kids_from_end, dict);
            }
        }

        // build the path with walk
        if (!meet.empty())
        {
#ifdef DEBUG
            cout << "meet: ";

            for_each(meet.begin(), meet.end(), printFunc);

            cout << endl;
#endif
            // put the meet into result
            for (set<string>::iterator it = meet.begin(); it != meet.end(); ++it)
            {
                vector<string> words(1, *it);
                result.push_back(words);
            }

            walk(result, kids_from_start);;

            for (size_t i = 0; i < result.size(); ++i)
            {
                reverse(result[i].begin(), result[i].end());
            }

            walk(result, kids_from_end);
        }
    }

    return result;
}

#ifndef EXPORTED
int main()
{
//    string s("abcd");
//    Permutation<string, char>(s, 0);
    string str[] = {"hot", "hit", "dot", "dog", "cog", "lot", "log"};
    set<string> dict(str, str + 7);
    vector< vector<string> > answers = findLadders2("hit", "cog", dict);

    for (vector< vector<string> >::iterator itr1 = answers.begin(); itr1 != answers.end(); ++itr1)
    {
        cout << "Solution:" << endl;

        for (vector<string>::iterator itr2 = (*itr1).begin(); itr2 != (*itr1).end(); ++itr2)
        {
            cout << *itr2 << "\t";
        }

        cout << endl;
    }

    return 0;
}
#endif
