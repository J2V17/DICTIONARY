#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>
#include "timemonitor.h"

namespace seneca {
    enum class PartOfSpeech {
        Unknown,
        Noun,
        Pronoun,
        Adjective,
        Adverb,
        Verb,
        Preposition,
        Conjunction,
        Interjection
    };

    struct Word {
        std::string m_word;
        std::string m_definition;
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
    };

    class Dictionary
    {
        Word* m_words;
        size_t m_size;


    public:
        Dictionary();
        Dictionary(const char* filename);
        ~Dictionary();
        //  string convertPSpeechToString(PartOfSpeech pos) ;
          //copy constructor
        Dictionary(const Dictionary& other);
        //copy assigment
        Dictionary& operator=(const Dictionary& other);
        //move
        Dictionary(Dictionary&& other) noexcept;
        Dictionary& operator=(Dictionary&& other)noexcept;

        PartOfSpeech getPartOfSpeech(const std::string& pos_str);
        void searchWord(const char* word);
    };
}

#endif // DICTIONARY_H
