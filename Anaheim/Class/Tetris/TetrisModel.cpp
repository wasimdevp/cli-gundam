#include "StdAfx.h"
#include "TetrisModel.h"
#include "TetrisField.h"
#include "TetrisMino.h"
#include "TetrisScore.h"

using namespace Anaheim;
using namespace Anaheim::Tetris;

TetrisModel::TetrisModel(Anaheim::Tetris::TetrisField ^field, System::Collections::Generic::List<TetrisMino^> ^minos, Anaheim::Tetris::TetrisScore ^score, int nextCount)
{
	this->field = field;
	this->minos = minos;
	this->score = score;
	this->nextCount = nextCount;
}
// ----------------------------------------------------------------------------------------------------

void TetrisModel::AddNextMinos()
{
	array<TetrisMino^>^ shuffleMino =
	{
		gcnew ITetrisMino(Point(3, 0), this->field),
		gcnew JTetrisMino(Point(3, 0), this->field),
		gcnew LTetrisMino(Point(3, 0), this->field),
		gcnew STetrisMino(Point(3, 0), this->field),
		gcnew ZTetrisMino(Point(3, 0), this->field),
		gcnew TTetrisMino(Point(3, 0), this->field),
		gcnew OTetrisMino(Point(3, 0), this->field)
	};

	Random^ random = gcnew Random();
	int n = shuffleMino->Length;
	while (1 < n)
	{
		n--;
		int k = random->Next(n + 1);
		TetrisMino^ temp = shuffleMino[k];
		shuffleMino[k] = shuffleMino[n];
		shuffleMino[n] = temp;
	}
	
	for each (TetrisMino^ mino in shuffleMino)
	{
		this->minos->Add(mino);
	}
}
// ----------------------------------------------------------------------------------------------------

bool TetrisModel::SetNewMino()
{
	this->minos->Remove(this->CurrentMino);

	while (this->minos->Count < this->nextCount + 1)
	{
		this->AddNextMinos();
	}

	return (this->CurrentMino->IsIllegalLocation()) ? false : true;
}
// ----------------------------------------------------------------------------------------------------

bool TetrisModel::EndDown()
{
	this->field->SetMino(this->CurrentMino);
	this->OnChangedField(gcnew EventArgs());

	int count = this->field->RemoveCompleteRows();
	
	bool isPerfect = this->field->IsEmpty;
	if (this->score->UpdateScore(count, isPerfect))
	{
		this->OnChangedScore(gcnew TetrisScoreEventArgs(this->score));
	}

	return this->SetNewMino();
}
// ----------------------------------------------------------------------------------------------------

void TetrisModel::Clear()
{
	this->field->Clear();
	this->minos->Clear();
	this->score->Clear();
	this->OnChangedScore(gcnew TetrisScoreEventArgs(this->score));
}
// ----------------------------------------------------------------------------------------------------

void TetrisModel::Initialize()
{
	this->Clear();
	this->SetNewMino();
}
// ----------------------------------------------------------------------------------------------------

bool TetrisModel::RotateRight()
{
	return this->CurrentMino->RotateRight();
}
// ----------------------------------------------------------------------------------------------------

bool TetrisModel::RotateLeft()
{
	return this->CurrentMino->RotateLeft();
}
// ----------------------------------------------------------------------------------------------------

bool TetrisModel::MoveRight()
{
	return this->CurrentMino->MoveRight();
}
// ----------------------------------------------------------------------------------------------------

bool TetrisModel::MoveLeft()
{
	return this->CurrentMino->MoveLeft();
}
// ----------------------------------------------------------------------------------------------------

bool TetrisModel::MoveDown()
{
	return this->CurrentMino->MoveDown();
}
// ----------------------------------------------------------------------------------------------------

bool TetrisModel::MoveDownAutomatic()
{
	if (!this->MoveDown())
	{
		bool result = this->EndDown();
		if (result)
		{
			this->OnTurnEnd(gcnew EventArgs());			
		}
		else
		{
			this->OnGameOver(gcnew TetrisScoreEventArgs(this->score));
		}

		return result;
	}

	return true;
}
// ----------------------------------------------------------------------------------------------------

bool TetrisModel::Teleport()
{
	TetrisMino^ ghost = this->CurrentMino->CreateGhost();
	this->CurrentMino->MoveTo(ghost);
	return this->CurrentMino->IsIllegalLocation();
}
// ----------------------------------------------------------------------------------------------------

void TetrisModel::OnTurnEnd(System::EventArgs ^e)
{
	this->TurnEnd(this, e);
}
// ----------------------------------------------------------------------------------------------------

void TetrisModel::OnChangedField(System::EventArgs ^e)
{
	this->ChangedField(this, e);
}
// ----------------------------------------------------------------------------------------------------

void TetrisModel::OnChangedScore(Anaheim::Tetris::TetrisScoreEventArgs ^e)
{
	this->ChangedScore(this, e);
}
// ----------------------------------------------------------------------------------------------------

void TetrisModel::OnGameOver(Anaheim::Tetris::TetrisScoreEventArgs ^e)
{
	this->GameOver(this, e);
}
// ----------------------------------------------------------------------------------------------------
