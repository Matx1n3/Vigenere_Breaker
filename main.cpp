#include <iostream>
#include <unordered_map>
#include <cmath>

int main() {

    int from;
    int to;
    std::string ciphertext = "qptqkkwlckhkmzpnkmupkcvkwzpicacgelmfwhzlzfnmfmcksh"
                            "cmfgvnfmrzbtpgybokwilfqbgqujbppqgbrmjiumcgliilzbrg"
                            "phqkwzhkbubwvvzlnmpmmbvigbqgvetsmlsuzxhagxkcbgrigj"
                            "qewarvyxzbrrpexezjikcbbuigmwbbmqnwoeoipmixrzzdxawh"
                            "gxkiuxyahkiykpbqqfascvvvpgcmmueehpsfmlkkpkcigbwkrd"
                            "xqlehtvzvzyvqxriigirqbgtxfdbbmfmlkgzhnpleeikqvrpvl"
                            "gultwytyuikoxeyqaxhczbaztbvojzizpizlerzkxgaphqslvb"
                            "aigbrmnqmfjbufukptpmvwitkqygmquchffxqiawxnvzxganem"
                            "tvjxrerxrzymfqqtgmlpqgebuxgudunlqptxofvxtmvlxnvmtt"
                            "mfwvugxxpauxerjwbqiohbgelayanwszkmwjqaxezkivfmqmsz"
                            "ymvmuznrotimgwalpoemlfmvlehcmmmqamixtmirbuxgudunlq"
                            "ptxofvmfmbgpenirrwckibvvmcdryvudtxyzabrmnptriybgkr"
                            "vwzwotvkkieiqazehfcmgagavuloayxexzkebbtmphytkmkkmn"
                            "lyxvmgazlixofvmfmexwtflxrmpmmuebaczrlruimlnwalizym"
                            "kcaahvojsfyvnzisvvmwwhaebvbhydbbhzymmfzrtxlfzwcknw"
                            "iynmaydrnwkubaganitxfivfbbvssgcmczfxgaiqmwerwvgnjh"
                            "vmftvulvwrprwmlwmkcvgipgpmkqiawpoemlzmgpikebacujxh"
                            "kwqgclvyjkimgrigmeibmkqmnoiyuzhnxrkwodxxpabgezfzlr"
                            "pvxzkjigbbuxmxtiiyjvemzzmlumhlivimocvgbzktwnlbrkqk"
                            "ranpmfemqvmgazlixofvtllnvgkjavmvgksrkwttwvwhownxpm"
                            "amxnimtravyaktigydbbhzymmfzrtxynmocebgmlnmvyvgpibv"
                            "thqbvfemzvxkgfnvviqlceuxrocmtpvrwxnrbmfmjhvrulhcaa"
                            "mauismfqfpeejwfcpvlxuigypwzmlkmqzcvrkiczsbnitxxnvn"
                            "bpagpirclhaczxrzvlwcapkmvkqhlwsttucgtjxutfkkqvaqca"
                            "ixnildwefyrrbxbjleiuejtrbvlxgrtuczgbexfcgbiawyyvlt"
                            "kmgtpizxaczqbwikwluqgvlhvbpcmavmvymkytcaehvblytoxv"
                            "zzalwagxquetrqevmgnvltjxutfkkatdbrkwkmmkytjhvjjigb"
                            "ajbxiymlumexmtuqvybrwfenzbrqazxnvtxrbrkslkpxawekiy"
                            "gwgbqazergptzmgbrzymvgxuxvzvfmjigxvoerhfiagiykzbrp"
                            "rfmajqgfqfpsxbxhjqtkevyqtgvixrzvlmfmgtfacikckgteii"
                            "qmgknegudxhlmamslkpxtqtxrxvkbnprkxnvbkgbuxqolavgxu"
                            "xvnfextmehrrpxkmdvwijrxkmoexwyzdxpqtbhgelipmqbgzrj"
                            "ecallxkdnhpajbxiyqgejrmakvvvgxuxvgcxayjrmwcyimgaah"
                            "aqewplifmlkmqzcvrkiizxaczjtwuiqzgvnepeumlazvuijsgz"
                            "gwitrhrbmgagtfkcttqwvglojjhmsytgowztbmylmmxqhtiaue"
                            "zkqlrioxprrahfmonmrkcimvgaizrjnjiexgzrwyrzvmlkdqnq"
                            "jhmejumwyzriigkqgekbnrzvzlgoatokpbhqevmgntqifmetpv"
                            "yiucbfxzkigecbgxvcymkciftphvzmgiawxxzbacuvnwajmwyn"
                            "vqijgimrmegsljcuqbvmyzzwgqjrepgjwlqkuxqkdmtlbgaivr"
                            "bmczahjyljlrqgnxofvlawhehhvmtqqyrgnrvzclfbqvcguwar"
                            "eiikqgeiaxaqvgdcgfpixvbrnqptprpabloyxauillmzfasxkx"
                            "apifxwqewplbbuszyxtpbvxwoeiwtiaviuibkyvffmzkmwmcgh"
                            "jhrvwytbgkczbarprfiyjizcjrepgjwlkmgasjkpnqzrjyoimw"
                            "qbehrmjmvszvmclfzhltlmlkbmryavmmyimeybvoirpmtqgghw"
                            "ktckcifasxksxwxukeyvatwjlttxvdbmcfivomimckbgzkiatr"
                            "qbgfkcttqwflcykmfuifvstjqwcznupedwkcarvyxvjeyqfxhk"
                            "mqzcvrkivljegauxhnzawcapkmvkqhlwstwodqeyzonxykzhlo"
                            "rkeakwdcgpbtnvzucnbkizymvmcemslymgpgvbmuwnkyvpxmtc"
                            "imczvgxnvbaamamyxpbacqaoitkqhlwsuircilmapbtnvzpyaz"
                            "bwgkbkgjhmijkwogorgixvlttqqdeneqgfqfusubbackbwihim"
                            "timelpgdmgrmqmlkdqlybgkmhlbbmvorwgpqgebutxnzammzla"
                            "ejzogmzrwxnzabkxbkxgebvmvgkmhlbbmvnghoeamciqgesvlt"
                            "pmtkiyjqociawirvuxlbnkcizxaczshvnzuogorgixvbamctal"
                            "kyiwlwgamtxbhbwjbxnzbmfmibkkemkckvilkiotgvrwexvxnr"
                            "igbstwwkzmvgkkokxnbvhrgctrqbehrmewmclnnxnfztllztxn"
                            "vutrqpbettptptrlpakebborwsjxahltrpmytikpwyeggctxbb"
                            "uxzoxmgczrvmvymksvokigbiujmvglojxbckrmlkrtifioxxiz"
                            "xaczvgeiyqebzrgwsrotxqaxmtjkbcvgbjotifczvvetumlazv"
                            "uijkpxtqtxrxvkbnprkeyzuimafbfrvwyrzngwrrbbmvgamyim"
                            "isbnmmueetqvbmhkjmktmqvlgitxqjnufgxmbqsahatkwaydru"
                            "vubmgydnkmgebhdbuxgogpxpifxexcgtqpbpibvzaclvwrzgcu"
                            "jqfalojehpsxtwojsbcvgbvkcgupwxxxnvkbnprketuxnztvll"
                            "kubacbrvltzyncqamlkkpvcvgnvevdxljrysxvbagagasaxplm"
                            "urlooctxbkertzrvtjgfmwifcebwpveyzwgytyrfxvidrprvmv"
                            "ymkgvgaizykxlbhkciigirwtkevyqvqtvwixltxsarweyrktjk"
                            "heezzwgyqquczymluqflexdgucbjxitrvwrprommvvxpmpbtnv"
                            "zbqavftrvmgmctaxusmtdqrehizxaczvymzzanqmqbrifvcsvp"
                            "mmueebrppbtnvzwgaxlxnvkhlnrwixrbxqbnmiyfntkmebggww"
                            "kcfnftrvclclnuvgjavgxuxvjzadrwvftrvuxlbgaibzoxlmex"
                            "gogpxplhkmtxbacizxvotigaqibpcrzmfmphrlvlxpiprwsval"
                            "yorlakimyyzskssjmvpmgtrjkpxsvvhrxvonjieeciiivimqml"
                            "kzzfcaftkkjbapwhzlulbmfmjtvzymvmvsxhkiimctrthkiaag"
                            "xckmsrzbjgexpovlnnwamlxvmdcgcavgjmlkiavlkjbxpjynjl"
                            "twfntrmibzkmmzltrjramfmjtviruxrwnvpujmvmurkiziqusb"
                            "vhrmztuczgoixeifrzvxhzfzxnivkxnvjkmsrggogpxpkexezz"
                            "vzrproixeiftqtxrkimvgxuxvoejnrvbfezkmkupnmlkuqwrpr"
                            "vmvymkuiflxoctostaxvgstxrwpkcvkigytllmymmklizlauis"
                            "ameroixvdxlbhtprptxbbbmlkfvxrqzxtguiipwitfrpcgzzrt"
                            "ogstxaqcaix";

    std::cout << "From: " << std::endl;
    std::cin >> from;
    std::cout << "To: " << std::endl;
    std::cin >> to;
    //std::cout << "Ciphertext: " << std::endl;
    //std::cin >> ciphertext;

    for (int k = from; k <= to; k++) {

        std::unordered_map<char, int> frequencies[k];
        float mean[k];
        float variance[k];
        float sd = 0;

        // Initialize the mean and variance arrays to 0
        for (int i = 0; i < k; i++) {
            mean[i] = 0;
            variance[i] = 0;
        }

        // Count the frequency of each letter for each of the k vectors
        // and sum the total number of letters in each vector
        for (int i = 0; i < ciphertext.size(); i++) {
            frequencies[i % k][ciphertext[i]] += 1;
            mean[i % k] += 1;
        }

        for (int i = 0; i < k; i++) {
            mean[i] /= 26;  // Divide by 26 to get the mean
            for (const auto &pair: frequencies[i]) {
                variance[i] += float(pow((float(pair.second) - mean[i]), 2));
            }
            variance[i] /= 26;
            sd += float(sqrt(double(variance[i])));
        }

        std::cout << "Key length: " << k << " SD: " << sd << std::endl;

        std::string likely_key = "";

        for (int i = 0; i < k; i++) {
            char most_frequent = 'a';
            for (const auto &pair: frequencies[i]) {
                if (pair.second > frequencies[i][most_frequent]) {
                    most_frequent = pair.first;
                }
            }
            char shift = char(((most_frequent - 'e') % 26) + 97);
            likely_key += shift;
        }

        std::cout << "Likely key for k = " << k << ": " << likely_key << std::endl;
    }
    return 0;
}
