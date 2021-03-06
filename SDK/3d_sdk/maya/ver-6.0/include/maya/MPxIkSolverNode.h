
#ifndef _MPxIkSolverNode
#define _MPxIkSolverNode
//
//-
// ==========================================================================
// Copyright (C) Alias Systems Corp., and/or its licensors ("Alias").  
// All rights reserved.  These coded instructions, statements, computer  
// programs, and/or related material (collectively, the "Material")
// contain unpublished information proprietary to Alias, which is
// protected by Canadian and US federal copyright law and by international
// treaties. This Material may not be disclosed to third parties, or be copied
// or duplicated, in whole or in part, without the prior written consent of
// Alias.  ALIAS HEREBY DISCLAIMS ALL WARRANTIES RELATING TO THE MATERIAL,
// INCLUDING, WITHOUT LIMITATION, ANY AND ALL EXPRESS OR IMPLIED WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// IN NO EVENT SHALL ALIAS BE LIABLE FOR ANY DAMAGES WHATSOEVER, WHETHER DIRECT,
// INDIRECT, SPECIAL, OR PUNITIVE, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, OR IN EQUITY, ARISING OUT OF OR RELATED TO THE
// ACCESS TO, USE OF, OR RELIANCE UPON THE MATERIAL.
// ==========================================================================
//+
//
// CLASS:    MPxIkSolverNode
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxIkSolverNode)
//
//  The base class for user defined IK solvers.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/MPxNode.h>

// *****************************************************************************

// DECLARATIONS

class MString;
class MArgList;
class MIkHandleGroup;
class MMatrix;
class MDoubleArray;

// *****************************************************************************

// CLASS DECLARATION (MPxIkSolverNode)

/// Base class for user defined IK solvers  (OpenMayaAnim)
/**

Derive from this class to create user-defined IK solvers.

*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MPxIkSolverNode : public MPxNode
{
public:
	///
	virtual ~MPxIkSolverNode();
	///
	virtual MPxNode::Type type() const;

	///
	virtual MStatus		preSolve();
	///
	virtual MStatus		doSolve();
	///
	virtual MStatus		postSolve( MStatus );

	///
	virtual MString		solverTypeName() const;

	///
	bool				rotatePlane(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setRotatePlane(bool rotatePlane);
	///
	bool				singleChainOnly(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setSingleChainOnly(bool singleChainOnly);
	///
	bool				positionOnly(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setPositionOnly(bool positionOnly);
	///
	bool				supportJointLimits(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setSupportJointLimits(bool supportJointLimits);
	///
	bool				uniqueSolution(MStatus *ReturnStatus = NULL) const;
	///
	MStatus				setUniqueSolution(bool uniqueSolution);

	/// OBSOLETE
	virtual bool		isSingleChainOnly() const;
	/// OBSOLETE
	virtual bool		isPositionOnly() const;
	/// OBSOLETE
	virtual bool		hasJointLimitSupport() const;
	/// OBSOLETE
	virtual bool		hasUniqueSolution() const;
	/// OBSOLETE
	virtual bool		groupHandlesByTopology() const;

	///
	virtual MStatus		setFuncValueTolerance( double tolerance );
	///
	virtual MStatus		setMaxIterations( int value );

	///
	MIkHandleGroup * 	handleGroup() const;
	///
	virtual void 		setHandleGroup( MIkHandleGroup* );
	///
	const MMatrix *		toWorldSpace() const;
	///
	const MMatrix *		toSolverSpace() const;
	///
	double 				funcValueTolerance() const;
	///
	int 				maxIterations() const;
	///
	virtual void 		snapHandle( MObject& handle );

	void				create();

protected:

	///
	MStatus				getJointAngles( MDoubleArray& ) const;
	///
	MStatus				setJointAngles( const MDoubleArray& );
	///
	void				setToRestAngles();

	///
	MPxIkSolverNode();

	static const char*	className();

private:
	void*	instance;

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxIkSolverNode */
