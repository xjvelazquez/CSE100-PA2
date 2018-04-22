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
 // if (word == NULL){
//	std::cout << "Null case";
 //    return false;
 // }

  std::pair<std::set<std::string>::iterator,bool> returnVal = ourSet.insert(word);

  bool val = returnVal.second;
	std::cout << "val: " << val;
  if (val == true){
     return true;
  }
  return false;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
//  if (word == NULL){
//	std::cout << "Null case";
//     return false;
//  }

  std::set<std::string>::iterator returnVal = ourSet.find(word);


  if (returnVal != NULL){
     return true;
  }
  return false;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
