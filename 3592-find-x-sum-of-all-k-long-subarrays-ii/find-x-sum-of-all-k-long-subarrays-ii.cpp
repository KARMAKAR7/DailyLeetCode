class Solution {
public:
    vector<long long> findXSum(vector<int>& a, int k, int x) {
    int n = a.size();
    vector<long long> ans;
    set<pair<int, int>> selected, waitlist;
    // selected is a min heap, waitlist is a max heap.

    long long skill_sum = 0;

    auto remove_candidate = [&](pair<int, int> cand) {
        // If this was a waitlisted candidate, they can simply back out of the
        // interview process.
        if (waitlist.find(cand) != waitlist.end()) {
            waitlist.erase(cand);
        }

        // If this candidate was already selected and they want to back out of
        // the interview process, pick the most proficient waitilisted
        // candidate.
        if (selected.find(cand) != selected.end()) {
            selected.erase(cand);
            skill_sum -= 1LL * cand.first * cand.second;
            if (!waitlist.empty()) {
                auto new_selection = *waitlist.rbegin();
                waitlist.erase(new_selection);
                selected.insert(new_selection);
                skill_sum += 1LL * new_selection.first * new_selection.second;
            }
        }
    };

    auto add_candidate = [&](pair<int, int> cand) {
        // A new candidate has arrived. Select them blindly, then reject the
        // least proficient selected candidate.
        selected.insert(cand);
        skill_sum += 1LL * cand.first * cand.second;

        // If we have selected more than k candidates, move one candidate to
        // the waiting list.
        if (selected.size() > x) {
            // Transfer the least eligible selected candidate to the waiting
            // list.
            auto rejection = *selected.begin();
            selected.erase(rejection);
            skill_sum -= 1LL * rejection.first * rejection.second;
            waitlist.insert(rejection);
        }
    };

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        pair<int, int> cand = {freq[a[i]], a[i]};
        // If the candidate already exists, remove it. We will reapply.
        if (freq[a[i]] > 0) {
            remove_candidate(cand);
        }
        freq[a[i]]++;
        cand = {freq[a[i]], a[i]};
        add_candidate(cand);

        if (i >= k) {
            // Decrease the skillset of the oldest candidate.
            // To do that, we remove the previous application and apply fresh
            // for the job.
            int out = i - k;
            cand = {freq[a[out]], a[out]};
            remove_candidate(cand);
            freq[a[out]]--;

            if (freq[a[out]] > 0) {
                cand = {freq[a[out]], a[out]};
                add_candidate(cand);
            }
        }

        if (i >= k - 1) {
            ans.push_back(skill_sum);
        }
    }
    return ans;
    }
};