#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    struct TrieNode {
        vector<int> indices;
        vector<TrieNode *> children;
        TrieNode() {
            children.resize(26, nullptr);
        }
    };

    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode *root = buildTrie(words);
        square.resize(words[0].size());

        for (int i = 0; i < words.size(); ++i) {
            square[0] = words[i];
            backtrack(words, 1, root);
        }

        return ans;
    }

    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();

        for (int i = 0; i < words.size(); ++i) {
            TrieNode *node = root;
            for (int j = 0; j < words[i].size(); ++j) {
                if (!node->children[words[i][j] - 'a']) {
                    node->children[words[i][j] - 'a'] = new TrieNode();
                }

                node = node->children[words[i][j] - 'a'];
                node->indices.push_back(i);
            }
        }

        return root;
    }

    void backtrack(vector<string> &words, int lvl, TrieNode *root) {
        if (lvl == words[0].size()) {
            ans.push_back(square);
            return;
        }

        string src;

        for (int i = 0; i < lvl; ++i) {
            src += square[i][lvl];
        }

        TrieNode *node = root;

        for (int i = 0; i < src.size(); ++i) {
            node = node->children[src[i] - 'a'];

            if (!node) {
                return;
            }
        }

        for (int i = 0; i < node->indices.size(); ++i) {
            square[lvl] = words[node->indices[i]];
            backtrack(words, lvl + 1, root);

        }
    }

    vector<vector<string>> wordSquares3(vector<string>& words) {
        m_num = words.size();
        m_sz = words[0].size();
        square.resize(m_sz);

        for (int i = 0; i < m_num; ++i) {
            for (int j = 0; j < m_sz; ++j) {
                umap[words[i].substr(0, j)].push_back(words[i]);
            }
        }

        build(0);
        return ans;
    }

    void build(int k) {
        if (k == m_sz) {
            ans.push_back(square);
            return;
        }

        string prefix;

        for (int i = 0; i < k; ++i) {
            prefix += square[i][k];
        }

        for (auto w: umap[prefix]) {
            square[k] = w;
            build(k + 1);
        }
    }

    vector<vector<string>> wordSquares2(vector<string>& words) {
        m_num = words.size();
        vector<vector<string>> res(m_num, vector<string>(1));

        for (int i = 0; i < m_num; ++i) {
            res[i][0] = words[i];
        }

        m_sz = words[0].size();

        for (int i = 1; i < m_sz; ++i) {
            vector<vector<string>> tmpAns;

            for (int j = 0; j < res.size(); ++j) {
                for (int k = 0; k < m_num; ++k) {
                    if (check(res[j], words[k])) {
                        res[j].push_back(words[k]);
                        tmpAns.push_back(res[j]);
                        res[j].pop_back();
                    }
                }
            }

            res.swap(tmpAns);
        }

        return res;
    }

    bool check(vector<string> &tmp, string &w) {
        int num = tmp.size();

        for (int i = 0; i < num; ++i) {
            if (w[i] != tmp[i][num]) {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> wordSquares1(vector<string>& words) {
        m_num = words.size();
        m_sz = words[0].size();

        vector<string> tmp(m_sz);
        check(words, tmp, 0);

        return ans;
    }

    void check(vector<string> &words, vector<string> &tmp, int j) {
        if (j >= m_sz) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < m_num; ++i) {
            if (valid(words[i], j, tmp)) {
                tmp[j] = words[i];
                check(words, tmp, j + 1);
            }
        }
    }

    bool valid(string &s, int j, vector<string> &tmp) {
        if (j > 0 && s[0] != tmp[0][j]) {
            return false;
        }

        for (int i = 0; i < j; ++i) {
            if (s[i] != tmp[i][j]) {
                return false;
            }
        }

        return true;
    }

private:
    vector<vector<string>> ans;
    int m_num;
    int m_sz;
    vector<string> square;
    unordered_map<string, vector<string>> umap;
};

int main()
{
    Solution sln;
    //vector<string> words = {"area","lead","wall","lady","ball"};
    //vector<string> words = {"abat","baba","atan","atal"};
    vector<string> words = {"ulus","mity","wind","chip","pill","pugh","flux","crib","sump","piss","fils","high","pipy","rusk","cuss","miri","pung","this","knit","hisn","zins","puns","tuff","ruth","whit","wild","burd","hubs","grin","kirs","zips","migg","lump","dint","jiff","spud","pith","rill","twit","pugs","ichs","jugs","simp","crus","bury","lisp","bund","fugs","prig","dusk","dirt","inns","mild","dups","hins","nigh","ring","muds","bisk","spin","tuts","puff","jill","grig","gist","bilk","gill","buck","slur","limn","firn","surf","girl","brit","ilks","typy","yirr","whir","undy","nill","rifs","husk","flus","sift","bids","swig","fuds","bush","birr","buff","buds","sims","ywis","suck","slit","irid","guck","fist","kris","dunk","didy","iffy","snub","luny","dull","stub","spic","buts","viny","bris","tump","phut","will","guff","putt","whid","tilt","slub","sris","pfft","mull","bill","turk","kith","grip","stun","hilt","skip","piny","curl","liri","lust","mirk","birl","musk","huts","tiff","tuns","ruin","burs","girn","juju","fuji","writ","suqs","much","iglu","lulu","bulb","gild","whig","yips","lips","riff","libs","gird","tils","whin","thru","tubs","hint","mumm","till","grid","bird","curb","rung","flit","glug","gimp","fink","sins","find","tick","mill","null","flip","cigs","subs","pits","tipi","zinc","skid","plus","grit","gnus","curf","turn","tiny","miff","gibs","nick","shit","linn","tint","bull","urbs","immy","gush","fury","tins","duff","wiss","pick","chum","junk","vugs","limb","sulk","kilt","buss","curr","ping","snug","tidy","khis","mids","with","frug","jinn","yill","fill","gulf","mush","list","swum","kink","cwms","quid","lunk","chug","urus","sulu","lutz","just","funk","firs","mixt","guts","gyps","yids","brin","silt","wigs","gigs","diss","mitt","hung","ribs","bhut","drum","pups","idly","pins","titi","ritz","slim","spik","furl","tics","sirs","must","shul","tips","burr","shin","suss","rush","lull","lift","zits","milk","puds","phiz","mick","tirl","nidi","film","ruts","stir","lung","pulp","lunt","ughs","sips","mibs","pily","kirn","glim","pirn","silk","luff","syph","birk","thin","butt","hums","smug","twin","kits","rink","tuft","wins","wuss","lush","tivy","unit","dump","duly","pity","hulk","trig","grub","curn","duns","kids","wist","tsks","flic","gits","mini","wing","zing","frig","lick","nixy","swim","yins","kiwi","nuns","cups","jism","vigs","puri","nurl","impi","quit","inly","syli","mugs","lurk","rims","spiv","duds","glum","dumb","rump","fixt","tyin","dips","bibs","wits","chub","king","buhr","virl","busy","scut","urns","scum","curs","gull","idyl","sync","smut","slum","sups","blin","suds","bubs","crud","firm","djin","sung","rich","runs","runt","suit","wink","bunn","pull","brut","slut","jibs","figs","gins","digs","wyns","hind","gips","mump","jigs","spur","dims","wynn","hips","nuts","dugs","ruck","sums","ding","nisi","girt","hunt","vill","clit","mutt","umps","gulp","puny","buys","trug","guid","duty","dits","spit","dung","yuch","guls","fumy","liny","prim","scud","shun","durr","ling","muns","rust","quiz","jibb","fuci","inti","guys","dirk","ills","whys","scry","ziti","crux","kind","huic","glut","sink","fubs","bind","ting","pigs","turd","tuis","gift","iwis","putz","kick","muss","mist","chid","kifs","ruly","mink","punk","skis","burn","lint","jump","pump","curt","bums","dink","murr","pimp","huns","fuzz","rimy","hull","yuks","fuck","fins","kuru","sudd","cuts","dipt","wynd","stum","city","nims","wily","sibs","unci","isms","psst","jink","bunt","pyic","ugly","sith","funs","myth","fibs","kudu","gilt","fuss","hunh","yurt","muts","rigs","rins","inks","rick","hiss","irks","puls","jinx","bulk","curd","purr","trip","such","hili","muck","hugs","vims","vugg","puss","limy","mils","midi","vugh","drub","hill","purl","huck","imid","duct","chit","miry","muni","litu","rift","kiln","buns","kips","tits","bitt","chis","fids","nurd","slip","rips","whiz","sics","brig","rhus","sing","dish","huff","rubs","sugh","sill","punt","lits","hurt","wiry","skim","hunk","cunt","plum","sunn","luvs","muff","brim","fizz","drib","piki","rynd","shiv","fisc","kirk","quin","sinh","pyin","purs","thud","knur","migs","grum","bins","burl","spun","blip","wych","cist","blub","icky","slid","wimp","lynx","tush","yuck","tusk","snit","hits","bits","grim","hump","mirs","mums","clip","fugu","skin","jury","cubs","pips","whip","pics","typp","lily","thir","mumu","smit","disc","pfui","blur","hymn","puts","wish","pink","bibb","gyms","bigs","tung","hick","puck","milt","itch","mind","cusk","uric","furs","guvs","guns","gink","nits","lich","shri","futz","duck","cris","duci","drip","illy","burp","minx","sild","brrr","lids","yird","guru","phis","wilt","fish","luck","link","psis","plug","bump","dins","lugs","burg","tuck","kill","jilt","wisp","drug","rugs","dust","shim","jimp","duit","push","pint","dill","disk","gyri","rind","lums","mint","ghis","rids","sizy","club","slug","scup","xyst","limp","imps","tups","sibb","cuff","tiki","stud","sits","nips","trim","bust","gums","wick","turf","fund","snip","cuds","fits","chin","tugs","inch","pish","hurl","thus","glib","murk","quip","flub","drys","dibs","pili","hyps","ruby","dick","bint","lins","wich","buhl","urds","zill","biff","kist","ibis","byrl","dubs","cull","puli","bumf","juts","gids","durn","surd","twig","friz","cusp","yups","hist","skit","kins","miss","nubs","chic","lilt","buzz","sign","frit","tutu","culm","sigh","whim","hush","bugs","winy","busk","inky","gunk","numb","sick","cult","risk","rudd","bunk","iris","ditz","inby","mugg","bung","zigs","rums","dirl","nils","pubs","jins","nibs","kiss","full","dunt","sunk","ship","pixy","suns","cyst","ruff","gust","thug","cuif","spry","snib","upby","shut"};
    vector<vector<string>> ans = sln.wordSquares(words);
    print2DVector<string>(ans);
    return 0;
}
