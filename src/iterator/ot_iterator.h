/******************************************************************************
 *                                                                            *
 * Copyright (c) 2015, Tsung-Wei Huang and Martin D. F. Wong,                 *
 * University of Illinois at Urbana-Champaign (UIUC), IL, USA.                *
 *                                                                            *
 * All Rights Reserved.                                                       *
 *                                                                            *
 * This program is free software. You can redistribute and/or modify          *
 * it in accordance with the terms of the accompanying license agreement.     *
 * See LICENSE in the top-level directory for details.                        *
 *                                                                            *
 ******************************************************************************/

#ifndef OT_ITERATOR_H_
#define OT_ITERATOR_H_

#include "ot_classdef.h"
#include "ot_typedef.h"
#include "ot_dictionary.h"
#include "ot_celllib.h"
#include "ot_verilog.h"
#include "ot_circuit.h"
#include "ot_timer.h"
#include "ot_rctree.h"
#include "ot_cppr.h"
#include "ot_path.h"

namespace __OpenTimer {

// Class: CircuitGateIter
// Iter of the gate set in a given circuit_uit.
class CircuitGateIter {
  
  public:

    CircuitGateIter(circuit_pt);
    ~CircuitGateIter();

    gate_pt gate_ptr() const;

    bool_t operator ()() const;
    void_t operator ++();

  private:
    circuit_pt _circuit_ptr;
    gate_dict_iter_t _i;
};

//-------------------------------------------------------------------------------------------------

// Class: CircuitNetIter
// Iter of the net set in a given circuit_uit.
class CircuitNetIter {
  
  public:

    CircuitNetIter(circuit_pt);
    ~CircuitNetIter();

    net_pt net_ptr() const;

    bool_t operator ()() const;
    void_t operator ++();

  private:
    circuit_pt _circuit_ptr;
    net_dict_iter_t _i;
};

//-------------------------------------------------------------------------------------------------

// Class: CircuitPinIter
// Iter of the pin set in a given circuit_uit.
class CircuitPinIter {
  
  public:

    CircuitPinIter(circuit_pt);
    ~CircuitPinIter();

    pin_pt pin_ptr() const;

    bool_t operator ()() const;
    void_t operator ++();

  private:
    circuit_pt _circuit_ptr;
    pin_dict_iter_t _i;
};

//-------------------------------------------------------------------------------------------------

// Class: CircuitPrimaryInputIter
// Iter of the pi set in a given circuit_uit.
class CircuitPrimaryInputIter {
  
  public:

    CircuitPrimaryInputIter(circuit_pt);
    ~CircuitPrimaryInputIter();

    primary_input_pt primary_input_ptr() const;

    bool_t operator ()() const;
    void_t operator ++();

  private:
    circuit_pt _circuit_ptr;
    primary_input_dict_iter_t _i;
};

//-------------------------------------------------------------------------------------------------

// Class: CircuitPrimaryOutputIter
// Iter of the po set in a given circuit_uit.
class CircuitPrimaryOutputIter {
  
  public:

    CircuitPrimaryOutputIter(circuit_pt);
    ~CircuitPrimaryOutputIter();

    primary_output_pt primary_output_ptr() const;

    bool_t operator ()() const;
    void_t operator ++();

  private:
    circuit_pt _circuit_ptr;
    primary_output_dict_iter_t _i;
};

//-------------------------------------------------------------------------------------------------

// Class: NetPinlistIter
// Iter of the pin pointer list in a give net.
class NetPinlistIter {
  
  public:
  
    NetPinlistIter(net_pt);
    ~NetPinlistIter();

    pin_pt pin_ptr() const;

    bool_t operator ()() const;
    void_t operator ++();

  private:

    net_pt _net_ptr;
    pinlist_iter_t _i;
};

//-------------------------------------------------------------------------------------------------

// Class: LibraryCellIter
// Iter of the cell set in a given library.
class LibraryCellIter {

  public:

    LibraryCellIter(celllib_pt);                            // Constructor.
    ~LibraryCellIter();                                     // Destructor.
    
    cell_pt cell_ptr() const;                               // Query the cellpin pointer.

    bool_t operator ()() const;                             // Query the end of iterator.
    void_t operator ++();                                   // Proceed to the next iteration.
  
  private: 

    celllib_pt _celllib_ptr;                                // Cell library pointer.
    cell_dict_iter_t _i;                                    // Dictionary iterator.
};

//-------------------------------------------------------------------------------------------------

// Class: LUTTemplateIter
class LUTTemplateDictIter {
  
  public:
    
    LUTTemplateDictIter(lut_template_dict_pt);              // Constructor.
    ~LUTTemplateDictIter();                                 // Destructor.

    lut_template_pt lut_template_ptr() const;               // Query the lut template pointer.
    
    bool_t operator ()() const;                             // Query the iterator status.
    void_t operator ++();                                   // Proceed to the next iteration.

  private:

    lut_template_dict_pt _lut_template_dict_ptr;            // Dictionary pointer.
    lut_template_dict_iter_t _i;                            // Iterator type.
};

//-------------------------------------------------------------------------------------------------

// Class: CellpinIter
// Iter of the set of cellpins in a given cell.
class CellpinIter {

  public:

    CellpinIter(cell_pt);                                   // Constructor.
    ~CellpinIter();                                         // Destructor.
    
    cellpin_pt cellpin_ptr() const;                         // Query the cellpin pointer.

    bool_t operator ()() const;                             // Query the end of iterator.
    void_t operator ++();                                   // Proceed to the next iteration.
  
  private: 

    cell_pt _cell_ptr;                                      // Cell pointer.
    cellpin_dict_iter_t _i;                                 // Dictionary iterator.
};

//-------------------------------------------------------------------------------------------------

// Class: CellpinEarlyLateIter
// Iter of the cellpins in a given early/late cell pair.
class CellpinEarlyLateIter {
  
  public:

    CellpinEarlyLateIter(cell_pt, cell_pt);                 // Constructor.
    ~CellpinEarlyLateIter();                                // Destructor.

    cellpin_pt cellpin_ptr(int) const;                      // Query the cellpin pointer.
    string_crt cellpin_name() const;                        // Query the cellpin name.
    pin_direction_e cellpin_direction() const;              // Query the cellpin direction.

    bool_t operator ()() const;                             // End of iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:
    
    cell_pt _cell_ptr[2];                                   // Cell pointer.
    cellpin_dict_iter_t _i[2];                              // Dictionary iterator.
};

//-------------------------------------------------------------------------------------------------

// Class: TimingArcIter
// Iter of the timing arc in a given cellpin.
class TimingArcIter {

  public:

    TimingArcIter(cellpin_pt, cellpin_pt);                  // Constructor.
    ~TimingArcIter();                                       // Destructor.
    
    timing_arc_pt timing_arc_ptr(int) const;                // Query the timing arc pointer.
    string_crt from_cellpin_name() const;                   // Query the from cellpin name.
    string_crt to_cellpin_name() const;                     // Query the to cellpin name.

    bool_t is_constraint() const;                           // Query the constraint status.
    bool_t operator ()() const;                             // Query the end of iterator.
    void_t operator ++();                                   // Proceed to the next iteration.
  
  private: 

    cellpin_pt _cellpin_ptr[2];                             // Cellpin pointer.
    timing_arc_dict_iter_t _i[2];                           // iterator.
};

//-------------------------------------------------------------------------------------------------

// Class: VerilogModuleIter
// Iter of the module set of a given pointer to a verilog obj.
class VerilogModuleIter {

  public:

    VerilogModuleIter(verilog_pt);                          // Constructor.
    ~VerilogModuleIter();                                   // Destructor.
    
    verilog_module_pt module_ptr() const;                   // Query the module pointer.

    bool_t operator ()() const;                             // Query the end of iterator.
    void_t operator ++();                                   // Proceed to the next iteration.
  
  private: 
    
    verilog_pt _verilog_ptr;                                // Verilog module pointer.
    verilog_module_dict_iter_t _i;                          // Module dictionary iterator.
};

//-------------------------------------------------------------------------------------------------

// Class: VerilogModuleInputIter
// Iter of the set of inputs in a given verilog module.
class VerilogModuleInputIter {

  public:

    VerilogModuleInputIter(verilog_module_pt);              // Constructor.
    ~VerilogModuleInputIter();                              // Destructor.
    
    verilog_input_pt input_ptr() const;                     // Query the primary input pointer.

    bool_t operator ()() const;                             // Query the end of iterator.
    void_t operator ++();                                   // Proceed to the next iteration.
  
  private: 
    
    verilog_module_pt _verilog_module_ptr;                  // Verilog module pointer.
    verilog_input_ptr_vec_iter_t _i;                        // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: VerilogModuleOutputIter
// Iter of the set of outputs in a given verilog module.
class VerilogModuleOutputIter {

  public:

    VerilogModuleOutputIter(verilog_module_pt);             // Constructor.
    ~VerilogModuleOutputIter();                             // Destructor.
    
    verilog_output_pt output_ptr() const;                   // Query the primary output pointer.

    bool_t operator ()() const;                             // Query the end of iterator.
    void_t operator ++();                                   // Proceed to the next iteration.
  
  private: 
    
    verilog_module_pt _verilog_module_ptr;                  // Verilog module pointer.
    verilog_output_ptr_vec_iter_t _i;                       // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: VerilogModuleWireIter
// Iter of the set of wires in a given verilog module.
class VerilogModuleWireIter {

  public:

    VerilogModuleWireIter(verilog_module_pt);               // Constructor.
    ~VerilogModuleWireIter();                               // Destructor.
    
    verilog_wire_pt wire_ptr() const;                       // Query the primary wire name.

    bool_t operator ()() const;                             // Query the end of iterator.
    void_t operator ++();                                   // Proceed to the next iteration.
  
  private: 
    
    verilog_module_pt _verilog_module_ptr;                  // Verilog module pointer.
    verilog_wire_ptr_vec_iter_t _i;                         // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: VerilogModuleGateIter
// Iter of the set of gate in a given verilog module.
class VerilogModuleGateIter {

  public:

    VerilogModuleGateIter(verilog_module_pt);               // Constructor.
    ~VerilogModuleGateIter();                               // Destructor.
    
    verilog_gate_pt gate_ptr() const;                       // Query the gate pointer.

    bool_t operator ()() const;                             // Query the end of iterator.
    void_t operator ++();                                   // Proceed to the next iteration.
  
  private: 
    
    verilog_module_pt _verilog_module_ptr;                  // Verilog module pointer.
    verilog_gate_ptr_vec_iter_t _i;                         // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: VerilogGateCellpinToNetMappingIter
// Iter of mapping set of an gate to a given verilog gate.
class VerilogGateCellpinToNetMappingIter {

  public:

    VerilogGateCellpinToNetMappingIter(verilog_gate_pt);    // Constructor.
    ~VerilogGateCellpinToNetMappingIter();                  // Destructor.

    char_cpt cellpin_name() const;                          // Query the cellpin name.
    char_cpt net_name() const;                              // Query the net name.
    
    bool_t operator ()() const;                             // Query the end of iterator.
    void_t operator ++();                                   // Proceed to the next iteration.
  
  private: 
    
    verilog_gate_pt _gate_ptr;                              // Verilog gate pointer.
    string_to_string_iter_t _i;                             // String to string map type.
};

//-------------------------------------------------------------------------------------------------

// Class: TimerEdgeIter
// Iter of the edges in a given timer.
class TimerEdgeIter {
  
  public:

    TimerEdgeIter(timer_pt);                                // Constructor.
    ~TimerEdgeIter();                                       // Destructor.

    edge_pt edge_ptr() const;                               // Edge pointer.

    bool_t operator ()() const;                             // Query the status of iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:
    timer_pt _timer_ptr;                                    // Timer pointer.    
    edgelist_iter_t _i;                                     // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: NodeFaninIter
// Iter of the fanin edges of a given node.
class NodeFaninIter {
  public:
    
    NodeFaninIter(node_pt);                                 // Constructor.
    ~NodeFaninIter();                                       // Destructor.

    edge_pt edge_ptr() const;                               // Edge pointer.
    edge_type_e edge_type() const;                          // Query the edge type.
    node_pt from_node_ptr() const;                          // From node pointer.
    
    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:

    node_pt _node_ptr;                                      // Node pointer.
    edgelist_iter_t _i;                                     // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: NodeFanoutIter
// Iter of the fanout edges of a given node.
class NodeFanoutIter {
  public:
    
    NodeFanoutIter(node_pt);                                // Constructor.
    ~NodeFanoutIter();                                      // Destructor.

    edge_pt edge_ptr() const;                               // Edge pointer.
    edge_type_e edge_type() const;                          // Query the edge type.
    node_pt to_node_ptr() const;                            // To node pointer.
    
    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:

    node_pt _node_ptr;                                      // Node pointer.
    edgelist_iter_t _i;                                     // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: NodeJumpinIter
// Iter of the fanin jumps of a given node.
class NodeJumpinIter {
  public:
    
    NodeJumpinIter(node_pt);                                // Constructor.
    ~NodeJumpinIter();                                      // Destructor.

    jump_pt jump_ptr() const;                               // Edge pointer.
    node_pt from_node_ptr() const;                          // From node pointer.
    
    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:

    node_pt _node_ptr;                                      // Node pointer.
    jumplist_iter_t _i;                                     // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: NodeJumpoutIter
// Iter of the fanout jumps of a given node.
class NodeJumpoutIter {
  public:
    
    NodeJumpoutIter(node_pt);                               // Constructor.
    ~NodeJumpoutIter();                                     // Destructor.

    jump_pt jump_ptr() const;                               // Edge pointer.
    node_pt to_node_ptr() const;                            // To node pointer.
    
    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:

    node_pt _node_ptr;                                      // Node pointer.
    jumplist_iter_t _i;                                     // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: RCTreeNodeIter
// Iter of the nodes in a given rctree.
class RCTreeNodeIter {
  
  public:

    RCTreeNodeIter(rctree_pt);                              // Constructor.
    ~RCTreeNodeIter();                                      // Destructor.

    rctree_node_pt rctree_node_ptr() const;                 // Node pointer.

    bool_t operator ()() const;                             // Query the status of iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:
    rctree_pt _rctree_ptr;                                  // RC tree pointer.    
    rctree_node_dict_iter_t _i;                             // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: RCTreeEdgeIter
// Iter of the edges in a given rctree.
class RCTreeEdgeIter {
  
  public:

    RCTreeEdgeIter(rctree_pt);                          // Constructor.
    ~RCTreeEdgeIter();                                  // Destructor.

    rctree_edge_pt rctree_edge_ptr() const;                 // Edge pointer.

    bool_t operator ()() const;                             // Query the status of iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:
    rctree_pt _rctree_ptr;                                  // RC tree pointer.    
    rctree_edgelist_iter_t _i;                             // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: RCTreeNodeFaninIter
// Iter of the fanin of a rctree node.
class RCTreeNodeFaninIter {
  public:
    
    RCTreeNodeFaninIter(rctree_node_pt);                // Constructor.
    ~RCTreeNodeFaninIter();                             // Destructor.

    rctree_edge_pt rctree_edge_ptr() const;                 // Edge pointer.
    
    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:

    rctree_node_pt _rctree_node_ptr;                        // RC tree node pointer.
    rctree_edgelist_iter_t _i;                             // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: RCTreeNodeFanoutIter
// Iter of the fanout of a rctree node.
class RCTreeNodeFanoutIter {
  public:
    
    RCTreeNodeFanoutIter(rctree_node_pt);               // Constructor.
    ~RCTreeNodeFanoutIter();                            // Destructor.

    rctree_edge_pt rctree_edge_ptr() const;                 // Edge pointer.
    
    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:

    rctree_node_pt _rctree_node_ptr;                        // RC tree node pointer.
    rctree_edgelist_iter_t _i;                              // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: NodelistIter
// Iterator of the node.
class NodelistIter {

  public:

    NodelistIter(nodelist_pt);                              // Constructor.
    ~NodelistIter();                                        // Destructor.

    node_pt node_ptr() const;                               // Node pointer.

    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:

    nodelist_pt _nodelist_ptr;                              // Nodelist pointer.
    nodelist_iter_t _i;                                     // Iterator.
};

//-------------------------------------------------------------------------------------------------

// Class: EdgelistIter
// Iterator of the edgelist.
class EdgelistIter {

  public:

    EdgelistIter(edgelist_pt);                              // Constructor.
    ~EdgelistIter();                                        // Destructor.

    edge_pt edge_ptr() const;                               // Edge pointer.
    node_pt from_node_ptr() const;                          // From node pointer.
    node_pt to_node_ptr() const;                            // To node pointer.

    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:

    edgelist_pt _edgelist_ptr;                              // Edgelist pointer.
    edgelist_iter_t _i;                                     // Iterator.
};

//-------------------------------------------------------------------------------------------------

// Class: SpefNetIter
// Iter of spefnets of a given spef object.
class SpefNetIter {
  public:

    SpefNetIter(spef_pt);                               // Constructor.
    ~SpefNetIter();                                     // Destructor.
    
    spefnet_pt spefnet_ptr() const;                         // Query the spefnet pointer.

    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:
    
    spef_pt _spef_ptr;                                      // Spef pointer.
    spefnet_ptr_vec_iter_t _i;                              // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: SpefPinIter
// Iter of spefpins of a given spef object.
class SpefPinIter {
  public:

    SpefPinIter(spefnet_pt);                            // Constructor.
    ~SpefPinIter();                                     // Destructor.

    spefpin_pt spefpin_ptr() const;                         // Query the spefpin pointer.

    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:
    
    spefnet_pt _spefnet_ptr;                                // Spefnets pointer.
    spefpin_ptr_vec_iter_t _i;                              // Iter.
};

//-------------------------------------------------------------------------------------------------
    
// Class: SpefCapIter
// Iter of spefcaps of a given spef object.
class SpefCapIter {
  public:

    SpefCapIter(spefnet_pt);                            // Constructor.
    ~SpefCapIter();                                     // Destructor.

    spefcap_pt spefcap_ptr() const;                         // Query the spefcap pointer.

    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:
    
    spefnet_pt _spefnet_ptr;                                // Spefnets pointer.
    spefcap_ptr_vec_iter_t _i;                              // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: SpefResIter
// Iter of spefcaps of a given spef object.
class SpefResIter {
  public:

    SpefResIter(spefnet_pt);                                // Constructor.
    ~SpefResIter();                                         // Destructor.

    spefres_pt spefres_ptr() const;                         // Query the spefres pointer.

    bool_t operator ()() const;                             // Query the status of the iterator.
    void_t operator ++();                                   // Increment the iterator.

  private:
    
    spefnet_pt _spefnet_ptr;                                // Spefnets pointer.
    spefres_ptr_vec_iter_t _i;                              // Iter.
};

//-------------------------------------------------------------------------------------------------

// Class: PathIter
// Iterate the path trace.
class PathIter {
  
  public:

    PathIter(path_pt);                                      // Constructor.
    PathIter(path_rt);                                      // Constructor.
    ~PathIter();                                            // Constructor.

    int rf() const;                                         // Rise/Fall
    node_pt node_ptr() const;                               // Node pointer.
    pin_pt pin_ptr() const;                                 // Pin pointer.

    bool_t operator ()() const;                             // Query the iter status.
    void_t operator ++();                                   // Increment.

  private:

    path_pt _path_ptr;                                      // Pointer to the path trace object.
    path_iter_t _i;                                         // Iterator.
};

//-------------------------------------------------------------------------------------------------

// Class: PathRIter
// Iterate the reversed path trace.
class PathRIter {
  
  public:

    PathRIter(path_pt);                                     // Constructor.
    PathRIter(path_rt);                                     // Constructor.
    ~PathRIter();                                           // Constructor.

    int rf() const;                                         // Rise/Fall
    node_pt node_ptr() const;                               // Node pointer.
    pin_pt pin_ptr() const;                                 // Pin pointer.

    bool_t operator ()() const;                             // Query the iter status.
    void_t operator ++();                                   // Increment.

  private:

    path_pt _path_ptr;                                      // Pointer to the path trace object.
    path_riter_t _i;                                        // Iterator.
};


};  // End of OpenTimer namespace. ----------------------------------------------------------------

#endif












