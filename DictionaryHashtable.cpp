#include "util.h"
#include "DictionaryHashtable.h"
#include <unordered_set> 
#include <string>

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{  
  std::pair<std::unordered_set<std::string>::iterator,bool> returnVal;
  returnVal = ourSet.insert(word);
  if (returnVal.second == true){
     return true;
  }

  return false;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  std::unordered_set<std::string>::const_iterator returnVal = ourSet.find(word);

  if (returnVal == ourSet.end()){
     return false;
  }
  return true;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
