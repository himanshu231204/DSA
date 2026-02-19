/*
🔍 Intuition (Why it works?)

🧠 Normal Boyer-Moore (for ⌊n/2⌋ case):
Ek candidate lete hain aur uska count track karte hain.

Jab same element milta hai → count++

Jab different milta hai → count--

Agar count 0 ho gaya to naye element ko candidate bana lete hain.

Kyunki agar ek element majority (> n/2) hai, toh wo last tak survive karega.

----------------------------------------------------
int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

=====================================================================

🔁 Extended Boyer-Moore (for ⌊n/3⌋ case):
Yaha max 2 elements ho sakte hain jinka frequency > ⌊n/3⌋ ho.

Isliye:

Hum 2 candidates maintain karte hain → elem1 and elem2

Saath hi unka count → cnt1 and cnt2

Agar kisi bhi element ka count zero ho jaaye:

Us element ko naye candidate ki tarah treat karte hain.

Ye approach kaam karta hai kyunki:

Agar ek element > ⌊n/3⌋ baar aata hai to wo total array mein significant majority rakhega.

Baaki elements ek dusre ko cancel kar denge, lekin true majority bacha rahega.

---------------------------------------------------------------------------------------------


vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}
*/





