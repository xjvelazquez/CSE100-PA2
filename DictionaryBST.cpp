#include "util.h"
#include "DictionaryBST.h"
#include <set>
#include <string>

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
   }

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{

  std::pair<std::set<std::string>::iterator,bool> returnVal = ourSet.insert(word);
  if (returnVal.second == true){
     return true;   // If the insert worked, return true
  }
  return false;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  std::set<std::string>::iterator returnVal = ourSet.find(word);


  if (returnVal == ourSet.end()){
     return false;   // If the word is not found, return false
  }
  return true;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
