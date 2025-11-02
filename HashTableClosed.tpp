template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int probes = 0;
    for(int i = 0; i < this->M; ++i)
    {
        probes++;
        int idx = this->probeIndex(key, i);
        if(!this->occupied[idx])        
        {
            this->table[idx] = key;
            this->occupied[idx] = true;
            this->N++;
            return probes;
        }

        if(this->table[idx]==key)
        {
            return probes;
        }
    }

    throw runtime_error("Hash table is full!");

    return 0;
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 

    int probes = 0;
    for(int i = 0; i < this->M; ++i)
    {
        probes++;
        int idx = this->probeIndex(key, i);

        if(!this->occupied[idx])
            return {false, probes};

        if(this->table[idx] == key)
            return {true, probes};
    }

    return {false, 0};
}
