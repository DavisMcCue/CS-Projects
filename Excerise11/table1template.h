// FILE: table1template.h
// TEMPLATE CLASS IMPLEMENTED: table (see table1.h for documentation)
// INVARIANT for the table ADT:
//   1. The number of records in the table is in the member variable used.
//   2. The actual records of the table are stored in the array data, with
//      a maximum of CAPACITY entries. Each used spot in the array has a 
//      non-negative key. Any unused record in the array has a key field of
//      NEVER_USED (if it has never been used) or PREVIOUSLY_USED (if it once
//      was used, but is  now vacant).

#include <cassert>  // Provides assert
#include <cstdlib>  // Provides size_t
#include <iostream>

namespace main_savitch_12A
{
    template <class RecordType>
    const std::size_t table<RecordType>::CAPACITY; 

    template <class RecordType>
    const int table<RecordType>::NEVER_USED;

    template <class RecordType>
    const int table<RecordType>::PREVIOUSLY_USED;

    template <class RecordType>
    table<RecordType>::table( )
    {
        std::size_t i;

        used = 0;
        for (i = 0; i < CAPACITY; ++i)
            data[i].key = NEVER_USED;  // Indicates a spot that's never been used.

// DO 1: Fill in this part by initializing EACH component of the metrics structure appropriately.
        metrics.tot_calls = 0;
        metrics.tot_comps = 0;
        metrics.min_comps = 1;
        metrics.max_comps = 0;

    }

    template <class RecordType>
    void table<RecordType>::insert(const RecordType& entry)
    // Library facilities used: cassert
    {
        bool already_present;   // True if entry.key is already in the table
        std::size_t index;        // data[index] is location for the new entry

        if (size() >= CAPACITY)
        {
            std::cout << "Table has no more space; entry with key " << entry.key << " not inserted." << std::endl;
            return;
        };

        assert(entry.key >= 0);

        // Set index so that data[index] is the spot to place the new entry.
        find_index(entry.key, already_present, index);

        // If the key wasn't already there, then find the location for the new entry.
        if (!already_present)
        {
            assert(size( ) < CAPACITY);
            index = hash(entry.key);
            while (!is_vacant(index))
                index = next_index(index, entry.key);
            ++used;
        }

        data[index] = entry;
    }

    template <class RecordType>
    void table<RecordType>::remove(int key)
    // Library facilities used: cassert
    {
        bool found;        // True if key occurs somewhere in the table
        std::size_t index;   // Spot where data[index].key == key

        assert(key >= 0);

        find_index(key, found, index);
        if (found)
        {   // The key was found, so remove this record and reduce used by 1.
            data[index].key = PREVIOUSLY_USED; // Indicates a spot that's no longer in use.
            --used;
        };
    }

    template <class RecordType>
    bool table<RecordType>::is_present(int key)
    // Library facilities used: assert.h
    {
        bool found;
        std::size_t index;

        assert(key >= 0);

        find_index(key, found, index);
        return found;
    }

    template <class RecordType>
    void table<RecordType>::find(int key, bool& found, RecordType& result)
    // Library facilities used: cassert.h
    {
        std::size_t index;

        assert(key >= 0);

        find_index(key, found, index);
        if (found)
            result = data[index];
    }

    template <class RecordType>
    inline std::size_t table<RecordType>::hash(int key) const
    {
        return (key % CAPACITY);
    }

    template <class RecordType>
    inline std::size_t table<RecordType>::hash2(int key) const
    {
        //PRE: When you implement double-hashing both CAPACITY and CAPACITY-2 should be prime numbers
        //return (1); // Linear probing
        return (1 + (key % (CAPACITY - 2))); //double hash
    }

    template <class RecordType>
    inline std::size_t table<RecordType>::next_index(std::size_t index, int key) const
    // Library facilities used: cstdlib
    {
        return ((index + hash2(key)) % CAPACITY);
    }

    template <class RecordType>
    void table<RecordType>::find_index(int key, bool& found, std::size_t& i)
    // Library facilities used: cstdlib
    {
	std::size_t count; // Number of entries that have been examined

	count = 0;
	i = hash(key);
	while((count < CAPACITY) && ++count && (data[i].key != NEVER_USED) && (data[i].key != key))
	{
	    //++count;
	    i = next_index(i, key);
	}
	found = (data[i].key == key);

    // DO 2: Fill in this part by updating EACH component of the metrics structure appropriately.

    metrics.tot_calls++;
    metrics.tot_comps += count;

    if (count < metrics.min_comps)
    {
        metrics.min_comps = count;
    }
    if (count > metrics.max_comps)
    {
        metrics.max_comps = count;
    }
    }

    template <class RecordType>
    inline bool table<RecordType>::never_used(std::size_t index) const
    {
	return (data[index].key == NEVER_USED);
    }
	
    template <class RecordType>
    inline bool table<RecordType>::is_vacant(std::size_t index) const
    {
	return (data[index].key == NEVER_USED) || (data[index].key == PREVIOUSLY_USED);
    }

    template <class RecordType>
    void table<RecordType>::stats () const
    {

// DO 3: Fill in this part by reporting the components of the metrics structure as indicated in the sample output.

        std::cout << "Min comparisions = " << metrics.min_comps << std::endl;
        std::cout << "Max comparisions = " << metrics.max_comps << std::endl;
        std::cout << "Average comparisons = " << float(metrics.tot_comps) / metrics.tot_calls << std::endl;
        std::cout << "Total number of searches = " << metrics.tot_calls << std::endl;
    }
}

