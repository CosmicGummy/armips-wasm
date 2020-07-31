#pragma once

class TempData;
class SymbolData;

struct ValidateState
{
	bool noFileChange = false;
	const wchar_t *noFileChangeDirective = nullptr;
};

class CAssemblerCommand
{
public:
	CAssemblerCommand();
	virtual ~CAssemblerCommand() { };
	virtual bool Validate(const ValidateState &state) = 0;
	virtual void Encode() const = 0;
	virtual void writeTempData(TempData& tempData) const = 0;
	virtual void writeSymData(SymbolData& symData) const { };
	void applyFileInfo();
	int getSection() { return section; }
	void updateSection(int num) { section = num; }
protected:
	int FileNum;
	int FileLine;
private:
	int section;
};

class DummyCommand: public CAssemblerCommand
{
public:
	bool Validate(const ValidateState &state) override { return false; }
	virtual void Encode() const { };
	virtual void writeTempData(TempData& tempData) const { };
	virtual void writeSymData(SymbolData& symData) const { };
};

class InvalidCommand: public CAssemblerCommand
{
public:
	bool Validate(const ValidateState &state) override { return false; }
	virtual void Encode() const { };
	virtual void writeTempData(TempData& tempData) const { };
	virtual void writeSymData(SymbolData& symData) const { };
};
