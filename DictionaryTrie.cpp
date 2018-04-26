#include "util.h"
#include "DictionaryTrie.h"

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
  root = new MWTNode();
}



/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  int alphabetSize = 27;
  MWTNode* curr = root;
  
  for (unsigned int index = 0; index < word.length(); index++){
    int letter = word[index] - 'a'; 

    // If the letter is a space
    if (word[index] == ' '){
      letter = alphabetSize-1;
    }
    
    // Checks for special chars
    else if (word[index] < 'a' || word[index] > 'z'){
      return false;
    }
   
    // If the pointer at letter is null 
    if (curr->alphaArray[letter] == NULL){
	curr->alphaArray[letter] = new MWTNode();
    }
    // If pointer already exists, move down the trie.
    curr = curr->alphaArray[letter];
  } 
  

  if (curr->endOfWord == true){
    if (freq > curr->frequency){  // Updates to new frequency
      curr->frequency = freq;
    }
    return false;  // Word already exists in trie.
  }
  
  curr->endOfWord = true; // Updates endOfWord to declare a word 
  curr->frequency = freq; // Updates frequency to declare frequency.
  return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
  int alphabetSize = 27;
  MWTNode* curr = root;
  
  for (unsigned int index = 0; index < word.length(); index++){
    int letter = word[index] - 'a'; 

    // If the letter is a space
    if (word[index] == ' '){
      letter = alphabetSize-1;
    }

    // Checks for special chars
    else if (word[index] < 'a' || word[index] > 'z'){
      return false;
    }

   
    // If the pointer at letter is null 
    if (curr->alphaArray[letter] == NULL){
	return false; // Word does not exist 
    }
    // If pointer already exists, move down the trie.
    curr = curr->alphaArray[letter];
  } 
  

  if (curr->endOfWord == true){
    return true;  // Word already exists in trie.
  }
  
  return false;
}

/* Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/*
 * Return the most similar word of equal length to the query, based
 * on their Hamming distance. 
 * In case of ties, return the word with the highest frequency (you may
 * assume there will always be one should a tie happen.)
 * In case there isn't any word of equal length to the query in the
 * trie, return an empty string.
 */
std::string DictionaryTrie::checkSpelling(std::string query)
{
  return "";
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
  deleteNode(this->root);
}

void DictionaryTrie::deleteNode(MWTNode *ourRoot){
  MWTNode *curr = ourRoot; // Creates tmp of root
  int alphabetSize = 27;

  for (int index = 0; index < alphabetSize; index++){
    if (curr->alphaArray[index] != NULL){
      deleteNode(curr->alphaArray[index]);  // Recursively goes through array.
    }
  }
  
  delete curr;
  return;
}


/* Getter for root */
MWTNode* DictionaryTrie::getRoot(){
  return root;
}

/* Constructor for MWTNode */

MWTNode::MWTNode(){
  frequency = 0;
  int alphabetSize = 27;
  endOfWord = false;
  for (int index = 0; index < alphabetSize; index++){
    alphaArray[index] = NULL;
  }
}

/* Destructor for MWTNode */
MWTNode::~MWTNode(){
  }



