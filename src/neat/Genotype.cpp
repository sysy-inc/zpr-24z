//
// Created by Maksymilian baj on 30.12.2024.
//

#include "Genotype.h"
#include <algorithm>
#include <unordered_set>

using namespace NEAT;

void Genotype::addNode(NodeInfo node) {
    nodes.push_back(node);
}

void Genotype::addEdge(EdgeInfo edge) {
    edges.push_back(edge);
}

std::vector<NodeInfo> Genotype::getNodes() const {
    return nodes;
}

std::vector<EdgeInfo> Genotype::getEdges() const {
    return edges;
}

std::vector<EdgeInfo>& Genotype::getEdges() {
    return edges;
}

size_t Genotype::getNodesCount() const {
    return nodes.size();
}

size_t Genotype::getEdgesCount() const {
    return edges.size();
}

EdgeInfo& Genotype::getEdge(int idx) {
    return edges[idx];
}

void Genotype::sortEdges() {
    std::sort(edges.begin(), edges.end(), [](const EdgeInfo& a, const EdgeInfo& b) {
        return a.innovation < b.innovation;
    });
}

void Genotype::sortNodes() {
    std::sort(nodes.begin(), nodes.end(), [](const NodeInfo& a, const NodeInfo& b) {
        return a.index < b.index;
    });
}

void Genotype::setEdges(const std::vector<EdgeInfo>& newEdges) {
    edges = newEdges;
}
void Genotype::addEdges(const std::vector<EdgeInfo>& newEdges) {
    edges.insert(edges.end(), newEdges.begin(), newEdges.end());
}

void Genotype::getInputAndOutputNodesFromParent(const NEAT::Genotype& parent) {
    for (const auto& node : parent.getNodes()) {
        if (node.type == NodeType::INPUT || node.type == NodeType::OUTPUT) {
            nodes.push_back(node);
        }
    }
}
void Genotype::updateHiddenNodes() {
    std::unordered_set<int> existingNodes;
    for (const auto& node : nodes) {
        existingNodes.insert(node.index);
    }

    for (const auto& edge : edges) {
        if (existingNodes.find(edge.sourceIdx) == existingNodes.end()) {
            nodes.push_back(NodeInfo(NodeType::HIDDEN, edge.sourceIdx));
            existingNodes.insert(edge.sourceIdx);
        }
        if (existingNodes.find(edge.destIdx) == existingNodes.end()) {
            nodes.push_back(NodeInfo(NodeType::HIDDEN, edge.destIdx));
            existingNodes.insert(edge.destIdx);
        }
    }
}
