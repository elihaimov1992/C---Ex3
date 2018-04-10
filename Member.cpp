#include "Member.h"

int Member::numOfMembers = 0;

int Member::numFollowers(){
    return numOfFollowers; 
}

int Member::numFollowing(){ 
    return numOfFollowing;
}

void Member::follow(Member& member){
        if(!isFollowing(&member)&&(this != &member)){
            numOfFollowing++; 
            member.numOfFollowers++;
            following.push_back(&member);
            member.followers.push_back(this);
        }
}
    
void Member::unfollow(Member& member){
    if(isFollowing(&member)&&(this != &member)){
            numOfFollowing--; 
            member.numOfFollowers--;
            tempUnfollow(&member);
    }
}
    
    void Member::unfollow2(Member* member){
        if(isFollowing(member)&&(this != member)){
            numOfFollowing--; 
            member->numOfFollowers--;
            tempUnfollow(member);
        }
    }
    
    bool Member::compare(Member* a, Member* b){
        return a == b;
    }
    
    bool Member::isFollowing(Member* member){
        bool ans = false;
        for (vector<Member*>::iterator it = following.begin(); it != following.end(); ++it){
            if(compare(*it, member)) ans = true;
        }
        return ans;
    }
    
    bool Member::isFollowedBy(Member* member){
        bool ans = false;
        for (vector<Member*>::iterator it = followers.begin(); it != followers.end(); ++it){
            if(compare(*it, member)) ans = true;
        }
        return ans;
    }
    
    void Member::tempUnfollow(Member* member){
        for(vector<Member*>::iterator it = following.begin(); it != following.end(); ++it){
    		if(compare(*it, member)) {
    			it = following.erase(it);
    			return;
    		} 
        }
    }
    
    void Member::unFollowAll(){
        int N = following.size();
        for (int i = 0; i < N; i++) { 
            this->unfollow2(following[0]);
        }
    }
    
    void Member::deleteAllFollowers(){ 
        int N = followers.size();
        for (int i = 0; i < N; i++) { 
            followers[i]->unfollow2(this);
        }
    }

    Member::Member(){ 
        numOfFollowers = 0;
        numOfFollowing = 0;
        numOfMembers++;
    }
    
    Member::~Member(){
        unFollowAll();
        deleteAllFollowers();
        numOfMembers--;
    }