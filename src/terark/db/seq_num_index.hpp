#ifndef __terark_db_seq_num_index_hpp__
#define __terark_db_seq_num_index_hpp__

#include "db_index.hpp"

namespace terark { namespace db {

// SeqNumIndex can be used as a primary key of Id
template<class Int>
class TERARK_DB_DLL SeqNumIndex :
	public ReadableIndex, public ReadableStore, public WritableIndex
{
	Int m_min;
	Int m_cnt;
	class MyIndexIterForward; friend class MyIndexIterForward;
	class MyIndexIterBackward; friend class MyIndexIterBackward;
	class MyStoreIter; friend class MyStoreIter;
public:
	SeqNumIndex(Int min, Int cnt);
	~SeqNumIndex();

	IndexIterator* createIndexIterForward(DbContext*) const override;
	IndexIterator* createIndexIterBackward(DbContext*) const override;
	llong indexStorageSize() const override;

	bool remove(fstring key, llong id, DbContext*) override;
	bool insert(fstring key, llong id, DbContext*) override;
	bool replace(fstring key, llong id, llong newId, DbContext*) override;
	void clear() override;

	llong dataStorageSize() const override;
	llong dataInflateSize() const override;
	llong numDataRows() const override;
	void getValueAppend(llong id, valvec<byte>* val, DbContext*) const override;

	StoreIterator* createStoreIterForward(DbContext*) const override;
	StoreIterator* createStoreIterBackward(DbContext*) const override;

	WritableIndex* getWritableIndex() override;
	ReadableIndex* getReadableIndex() override;
	ReadableStore* getReadableStore() override;
};

} } // namespace terark::db

#endif // __terark_db_seq_num_index_hpp__
