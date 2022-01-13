#include <stdio.h>
#include <chrono>
#include <vector>
#include <time.h>
#include <algorithm>
#include <random>
#include <string>
#include <thread>
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

vector<pair<string, vector<string>>> haraganaList = {
{"あ", {"a"}},
{"い", {"i"}},
{"う", {"u"}},
{"え", {"e"}},
{"お", {"o"}},
{"か", {"ka"}},
{"き", {"ki"}},
{"く", {"ku"}},
{"け", {"ke"}},
{"こ", {"ko"}},
{"さ", {"sa"}},
{"し", {"si", "shi"}},
{"す", {"su"}},
{"せ", {"se"}},
{"そ", {"so"}},
{"た", {"ta"}},
{"ち", {"ti", "chi"}},
{"つ", {"tu", "tsu"}},
{"て", {"te"}},
{"と", {"to"}},
{"な", {"na"}},
{"に", {"ni"}},
{"ぬ", {"nu"}},
{"ね", {"ne"}},
{"の", {"no"}},
{"は", {"ha"}},
{"ひ", {"hi"}},
{"ふ", {"hu", "fu"}},
{"へ", {"he"}},
{"ほ", {"ho"}},
{"ま", {"ma"}},
{"み", {"mi"}},
{"む", {"mu"}},
{"め", {"me"}},
{"も", {"mo"}},
{"や", {"ya"}},
{"ゆ", {"yu"}},
{"よ", {"yo"}},
{"ら", {"ra"}},
{"り", {"ri"}},
{"る", {"ru"}},
{"れ", {"re"}},
{"ろ", {"ro"}},
{"わ", {"wa"}},
{"ゐ", {"wi"}},
{"ゑ", {"we"}},
{"を", {"wo"}},
{"ん", {"n"}},
};

vector<pair<string, vector<string>>> katakanaList = {
{"ア", {"a"}},
{"イ", {"i"}},
{"ウ", {"u"}},
{"エ", {"e"}},
{"オ", {"o"}},
{"カ", {"ka"}},
{"キ", {"ki"}},
{"ク", {"ku"}},
{"ケ", {"ke"}},
{"コ", {"ko"}},
{"サ", {"sa"}},
{"シ", {"shi"}},
{"ス", {"su"}},
{"セ", {"se"}},
{"ソ", {"so"}},
{"タ", {"ta"}},
{"チ", {"chi"}},
{"ツ", {"tsu"}},
{"テ", {"te"}},
{"ト", {"to"}},
{"ナ", {"na"}},
{"ニ", {"ni"}},
{"ヌ", {"nu"}},
{"ネ", {"ne"}},
{"ノ", {"no"}},
{"ハ", {"ha"}},
{"ヒ", {"hi"}},
{"フ", {"fu"}},
{"ヘ", {"he"}},
{"ホ", {"ho"}},
{"マ", {"ma"}},
{"ミ", {"mi"}},
{"ム", {"mu"}},
{"メ", {"me"}},
{"モ", {"mo"}},
{"ヤ", {"ya"}},
{"ユ", {"yu"}},
{"ヨ", {"yo"}},
{"ラ", {"ra"}},
{"リ", {"ri"}},
{"ル", {"ru"}},
{"レ", {"re"}},
{"ロ", {"ro"}},
{"ワ", {"wa"}},
{"ヰ", {"wi"}},
{"ヱ", {"we"}},
{"ヲ", {"wo"}},
{"ン", {"n"}}
};

int finished = 0;
int total = haraganaList.size();
int error = 0;

void verify(pair<string, vector<string>> item, vector<pair<string, vector<string>>> &errorlist){
    printf("\033[1;37mGOJUON TEST\033[0m\tfinished \033[0;33m%d\033[0m/%d\terror \033[0;31m%d\033[0m\t \033[10;;93m(%s)\033[0m\n", finished, total, error, "press enter to continue...");
    printf("\033[1;33m%s\033[0m Roma spell is:", item.first.c_str());
    string answer;
    cin>>answer;
//    char c;
//    while((c=getchar()) !='\n'){
//        answer += c;
//    }
    if(answer.length() == 0){
        system("clear");
        verify(item, errorlist);
        return;
    }
    bool isright = false;
    for(string ans : item.second){
        if(ans == answer){
            isright = true;
            printf("\033[1;32m%s/%s\033[0m right!!!\n", item.first.c_str(), answer.c_str());
            break;
        }
    }
    if(not isright){
        printf("wrong answer \033[1;31m%s/%s\033[0m , correct one is \033[1;32m%s/%s\033[0m\n", item.first.c_str(),
                answer.c_str(), item.first.c_str(), item.second[0].c_str());
     //   printf("error ---------size:%d\n", item.second.size());
        error += 1;
        cin.get();
        errorlist.push_back(item);
    }
    finished += 1;
}

void shuffle(vector<pair<string, vector<string>>> &list){
    time_t t;
    srand((unsigned) time(&t));
    int len = list.size();
    for(int i=0;i<len;i++){
        int j = rand()%total;
        std::swap(list[i], list[j]);
    }
}

int main(){
    options:
    printf("choose practicing option:\n\
            a) hiragana\n\
            b) katakana\n\
            c) both\n");
    char opt = getchar();
    vector<pair<string, vector<string>>> charactersList;
    vector<pair<string, vector<string>>> errorlist;
    switch(opt){
        case 'a':
            charactersList = haraganaList;
            break;
        case 'b':
            charactersList = katakanaList;
            break;
        case 'c':
            for(auto item: haraganaList)
                charactersList.push_back(item);
            for(auto item: katakanaList)
                charactersList.push_back(item);
            for(auto item:charactersList)
                printf("%s---%s\n", item.first.c_str(), item.second[0].c_str());
            break;
        default:
            system("clear");
            printf("please choose providing option\n");
            goto options;
            break;
    }
    total = charactersList.size();
    shuffle(charactersList);
    for(auto item : charactersList){
        verify(item, errorlist);
        system("clear");
    }
    if(errorlist.size() > 0) cout<<"error list..."<<endl;
    for(auto item: errorlist){
        cout<<get<0>(item);
        if(get<1>(item).size()>1){
            cout<<" "<<get<1>(item)[0]<<"/"<<get<1>(item)[1]<<endl;
        }else{
            cout<<" "<<get<1>(item)[0]<<endl;

        }
    }
    printf("\033[1;37mGOJUON TEST\033[0m\tfinished \033[0;33m%d\033[0m/%d\terror \033[0;31m%d\033[0m\t \033[10;;93m(%s)\033[0m\n", finished, total, error, "press enter to continue...");
    return 0;
}
