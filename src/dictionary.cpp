#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "settings.h"
#include <iomanip>
using namespace std;
namespace seneca
{
    Dictionary::Dictionary() {}

    Dictionary::Dictionary(const char* filename) : m_words(nullptr), m_size(0)
    {
        cout << "Opening file: " << filename << std::endl;
        string line;

        int index = 0;
        std::ifstream file(filename);
        //check for error
        if (!file) {
            std::cerr << "Error" << filename << std::endl;
            return;
        }

        //read whole file once and count each lines
        while (getline(file, line))
        {
            //add size
            m_size++;
        }
        //to clear eof on the above while
        file.clear();
        file.seekg(0);
        //read the file again
        if (m_size > 0)
        {
            m_words = new Word[m_size];
        }
        else {
            std::cerr << "File is empty or invalid format." << std::endl;
            return;
        }
        while (getline(file, line) && index < m_size)
        {
            stringstream ss(line);
            string word, pos_str, definition;
            std::getline(ss, word, ',');
            std::getline(ss, pos_str, ',');
            std::getline(ss, definition);

            //storing the word and def in an array
            if (!word.empty() && !definition.empty())
            {
                m_words[index].m_word = word;
                m_words[index].m_definition = definition;
                m_words[index].m_pos = getPartOfSpeech(pos_str);
                index++;
            }
        }
        cout << "Successfully loaded " << m_size << " words from the file." << endl;
    }

    Dictionary::Dictionary(const Dictionary& other)
    {
        *this = other;
    }

    Dictionary& Dictionary::operator = (const Dictionary& other)

    {
        if (this != &other)
        {
            delete[] m_words;
            m_size = other.m_size;

            m_words = new Word[m_size];
            for (size_t i = 0; i < m_size; i++)
            {
                m_words[i] = other.m_words[i];
            }
            return *this;

        }
        else
        {
            return *this;
        }
    }
    Dictionary::Dictionary(Dictionary&& other) noexcept

    {
        *this = move(other);
    }
    Dictionary& Dictionary::operator=(Dictionary&& other) noexcept
    {
        if (this != &other)
        {
            delete[] m_words;
            m_words = nullptr;



            m_words = other.m_words;
            m_size = other.m_size;

            other.m_words = nullptr;
            other.m_size = 0;

            return *this;

        }

        return *this;
    }

    string convertPSpeechToString(PartOfSpeech pos)
    {
        switch (pos)
        {
        case PartOfSpeech::Noun:
            return "noun";
        case PartOfSpeech::Pronoun:
            return "pronoun";
        case PartOfSpeech::Adjective:
            return "adjective";
        case PartOfSpeech::Adverb:
            return "adverb";
        case PartOfSpeech::Verb:
            return "verb";
        case PartOfSpeech::Preposition:
            return "preposition";
        case PartOfSpeech::Conjunction:
            return "conjunction";
        case PartOfSpeech::Interjection:
            return "interjection";
        case PartOfSpeech::Unknown:
        default:
            return "unknown";
        }

    }

    Dictionary::~Dictionary() {
        delete[] m_words;
    }

    /*void Dictionary::resize() {
        size_t new_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        Word* temp = new Word[new_capacity];
        for (int i = 0; i < m_size; ++i) {
            temp[i] = m_words[i];
        }
        delete[] m_words;
        m_words = temp;
        m_capacity = new_capacity;
    }*/

    PartOfSpeech Dictionary::getPartOfSpeech(const std::string& pos_str) {
        if (pos_str == "n." || pos_str == "n. pl.") return PartOfSpeech::Noun;
        if (pos_str == "adv.") return PartOfSpeech::Adverb;
        if (pos_str == "a.") return PartOfSpeech::Adjective;
        if (pos_str == "v." || pos_str == "v. i." || pos_str == "v. t." || pos_str == "v. t. & i.") return PartOfSpeech::Verb;
        if (pos_str == "prep.") return PartOfSpeech::Preposition;
        if (pos_str == "pron.") return PartOfSpeech::Pronoun;
        if (pos_str == "conj.") return PartOfSpeech::Conjunction;
        if (pos_str == "interj.") return PartOfSpeech::Interjection;
        return PartOfSpeech::Unknown;
    }

    void Dictionary::searchWord(const char* word)
    {
        bool found = false;
        for (size_t i = 0; i < m_size; i++)
        {
            if (m_words[i].m_word == word)
            {
                if (!found)
                {
                    std::cout << m_words[i].m_word;
                    if (g_settings.m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown)
                    {
                        std::cout << " - (" << convertPSpeechToString(m_words[i].m_pos) << ") ";
                    }
                    else
                    {
                        std::cout << " - ";
                    }
                    std::cout << m_words[i].m_definition << std::endl;
                    found = true;
                }
                else
                {
                    std::cout << std::setw(m_words[i].m_word.length()) << std::right << " " << " - ";
                    if (g_settings.m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown)
                    {
                        std::cout << "(" << convertPSpeechToString(m_words[i].m_pos) << ") ";
                    }
                    std::cout << m_words[i].m_definition << std::endl;
                }

                if (!g_settings.m_show_all)
                {
                    return;
                }
            }
        }

        if (!found)
        {
            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
        }
    }
}
